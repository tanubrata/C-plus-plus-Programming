/*
Name: Tanubrata Dey
Course: CSCI 135
Instructor: Gennadiy Maryash
Task: Project_2_Task-A

This following program asks for a file containing DNA strands with 
codon as input and output the transcribed DNA strand to mRNA
strand as output
*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;

char DNAbase_to_mRNAbase(char c);//converts DNA to mRNA by capitalizing the strand
string DNA_to_mRNA(string dna_strand);//converts whole strand line by line

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

int main() {

	ifstream fin("dna.txt");
    if (fin.fail()) {
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }
	
	string strand;
	while(getline(fin, strand)) {
		cout << DNA_to_mRNA(strand) << endl;
	}
	
	fin.close();
	return 0;
}
