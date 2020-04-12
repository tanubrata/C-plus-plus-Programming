/******************************************************************************
Name: Tanubrata Dey
Course: CSCI 135
Instructor: Gennadiy Maryash
Task: Project_2_Task-D

This following program asks for a file containing DNA strands from task B 
as input , then transcribes DNA strand to mRNA strand and then translates
them into particular amino acid based on 3 bases and output the frameshift mutation version.
*******************************************************************************/
#include <iostream> 
#include <string> 
#include <fstream> 
#include <cstdlib> 

using namespace std; 

char DNAbase_to_mRNAbase(char c); //converts DNA to mRNA by capitalizing the strand
string DNA_to_mRNA(string DNA_strand); //converts whole strand line by line
string dictionary_read(ifstream &dict, string codon);//searches for translation in the given dictionary using 3 letter code
string mRNA_to_protein(ifstream &dict, string mRNA); //converts whole mRNA strand into specific amino acids
int hamming_Dist(string v, string w); //function to calculate the hamming distance between two strings

char DNAbase_to_mRNAbase(char c){

    char upper_c = toupper(c); 
    if (upper_c == 'A'){//A = U
        return 'U';
    } 
    if (upper_c == 'T'){//T = A
        return 'A';
    } 
    if (upper_c == 'C'){//C = G
        return 'G';
    }  
    if (upper_c == 'G'){//G = C
        return 'C';
    } 
} 

string DNA_to_mRNA(string DNA_strand){//convert DNA strand into mRNA
    string mRNA_strand; 
    for(int i = 0; i < DNA_strand.length(); i++){
        mRNA_strand += DNAbase_to_mRNAbase(DNA_strand[i]);//converts each codon and adds up all codons of mRNA to make whole strand
    } 
    return mRNA_strand;
} 

string dictionary_read(ifstream &dict, string codon) {//added codon part to take 3 bases together and translate
    
    string key, value;
    dict.clear(); // reset error state
    dict.seekg(0); // return file pointer to the beginning
    while (dict >> key >> value) {
        if(key == codon){
            return value;//return the translated part
        }
    }
} 

string mRNA_to_protein(ifstream &dict, string mRNA) { //converts mRNA strand into designated aminoacids depending in dictionary

    bool mRNA_encode = false;
    string aminoacid;

    for(int i = 0; i < mRNA.length(); i += 3){//adds up by 3 nucleotides 
        if(dictionary_read(dict, mRNA.substr(i , 3)) == "Met"){ //an if condition to start translating if AUG
            mRNA_encode = true; // if first is Met start process
        } 
        if(dictionary_read(dict, mRNA.substr(i , 3)) == "Stop"){ //an if condition to stop translation if reads a STOP codon and terminates
            mRNA_encode = false; 
        }  
        if(mRNA_encode == true){ //if a start codon then translates all after start codon
            aminoacid = aminoacid + dictionary_read(dict, mRNA.substr(i , 3)); 
        }                         
    } 
    return aminoacid;    
}

int hamming_Dist(string v, string w){
    int num = 0; //assign hamming to 0
    for(int i = 0; i < v.length(); i++){
        if(v[i] != w[i]){//if each code of string x is not equal to each code of string y respective to x, add hamming by 1.
            num += 1;
        }
    } 
    return num;// returns hamming number

}

void frameshift_mutation(ifstream &dict, string mRNA, int start_point) {//helper function to search for frameshift mutation
	int methyl_count = 0;
	bool mRNA_encode = false;
		
	for (int i = start_point; i < mRNA.length(); i+=3) {//adds up by 3 nucleotides
		if (dictionary_read(dict, mRNA.substr(i, 3)) == "Met") {//an if condition to start translating if AUG
			mRNA_encode = true;
			methyl_count += 1;
		}
		if ((dictionary_read(dict, mRNA.substr(i, 3)) == "Stop") || (methyl_count > 1)) {//an if condition to stop translation if reads a STOP codon and terminates
			mRNA_encode = false;
		}
		if (mRNA_encode == true) {//if a start codon then translates all after start codon
			cout << dictionary_read(dict, mRNA.substr(i , 3));
		}
		if ((mRNA_encode == true) && dictionary_read(dict, mRNA.substr((i + 3), 3)) != "Stop") {//adds a '-' after translating each codon
			cout << "-";
		}
	}
	cout << endl;
}

int main(){

    ifstream fin("frameshift_mutations.txt");//input frameshift mutation file in fin
    if (fin.fail()) {
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    } 

    ifstream dict("codons.tsv");//assign an ifstream for codons
	if(dict.fail()) 
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}

    string strand_a; 
    string strand_b;

    while(getline(fin, strand_a)) {        
        getline(fin, strand_b); //get second dna strand immediately after
        string mRNA = DNA_to_mRNA(strand_a); //1st DNA into 1st mRNA strand
        string mutated_mRNA = DNA_to_mRNA(strand_b);//2nd DNA strand into 2nd mRNA strand for frameshift mutation
        int mutated_start = mutated_mRNA.find("AUG", 0);//setting start point for mutated strand
		
		frameshift_mutation(dict, mRNA, 0);//using frameshift helper function for 1st strand
		frameshift_mutation(dict, mutated_mRNA, mutated_start);//using frameshift helper for 2nd strand
    }
    
    fin.close(); 
    dict.close();
    return 0; 

}  