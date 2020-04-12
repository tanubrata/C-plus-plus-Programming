/*
Name: Tanubrata Dey
Course: CSCI 135
Instructor: Gennadiy Maryash
Task: Project_2_Task-B

This following program asks for a file containing DNA strands with 
codon as input , the transcribes DNA strand to mRNA strand and then translates
them into particular amino acid based on 3 bases
*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;

char DNAbase_to_mRNAbase(char c);//converts DNA to mRNA by capitalizing the strand
string DNA_to_mRNA(string DNA_strand);//converts whole strand line by line
string dictionary_read(ifstream &dict, string codon);//searches for translation in the given dictionary using 3 letter code

char DNAbase_to_mRNAbase(char c) {

    char upper_c = toupper(c); 
    if (upper_c == 'A') { //A = U
        return 'U';
    }	 
    else if (upper_c == 'T') { //T = A
        return 'A';
    } 	
    else if (upper_c == 'C') { //C = G
        return 'G';
    }  
    else if (upper_c == 'G') { //G = C
        return 'C';
    } 
} 

string DNA_to_mRNA(string DNA_strand) {
	string mRNA_strand;
	
	for(int i = 0; i < DNA_strand.length(); i++) {
		mRNA_strand = mRNA_strand + DNAbase_to_mRNAbase(DNA_strand[i]);//converts each codon and adds up all codons of mRNA to make whole strand
	}
	
	return mRNA_strand;
}

string dictionary_read(ifstream &dict, string codon) {//added codon part to take 3 bases together and translate
    string key, value;
    dict.clear(); // reset error state
    dict.seekg(0); // return file pointer to the beginning
    while (dict >> key >> value) {
		if (key == codon) {
			return value;//return the translated part
		}
    }
}

int main() {

	ifstream fin("dna2b.txt");
    if (fin.fail()) {
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
    }
	
	ifstream dict("codons.tsv");//assign an ifstream for codons
	if(dict.fail()) {
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}
	
	string strand;
	while(getline(fin, strand)) {
		string mRNA = DNA_to_mRNA(strand);
		bool mRNA_encode = false;
		
		 for (int i = 0; i < mRNA.length(); i+=3) {//adds up by 3 nucleotides
		 	if (dictionary_read(dict, mRNA.substr(i, 3)) == "Met") {//an if condition to start translating if AUG
				mRNA_encode = true;
			}
			if (dictionary_read(dict, mRNA.substr(i, 3)) == "Stop") {//an if condition to stop translation if reads a STOP codon and terminates
				mRNA_encode = false;
			}
			if (mRNA_encode == true) {//if a start codon then translates all after start codon
				cout << dictionary_read(dict, mRNA.substr(i , 3));
			}
			if ((mRNA_encode == true) && dictionary_read(dict, mRNA.substr((i + 3), 3)) != "Stop") {//adds a '-' after translating each codon
				cout << "-";
			}
		 }
		 cout << endl << endl;
	}
	
	fin.close();
	dict.close();
	return 0;
}
