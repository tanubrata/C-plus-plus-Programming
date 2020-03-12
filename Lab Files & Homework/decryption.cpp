/******************************************************************************

Name: Tanubrata Dey
Course: CSCI 136
Instructor: Minh Nguyen
Task: Lab6D

This program asks to input a string, keyword & space and output the encrypted and decrypted of caesar and vigenere
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;


    char shiftChar(char c, int rshift) {
        char shifted_c;
        if (isupper(c)) { //for upper
            shifted_c = (c - 'A' + rshift) % 26 + 'A';
        }
        
        else if(islower(c))//for lower
        {
            shifted_c = (c - 'a' + rshift) % 26 +'a';
        }
        
        else {
            shifted_c = c;
        }
        
        return shifted_c;
    }
    
    string encryptCaesar(string plaintext, int rshift) {
        string ciphertext = ""; //empty string
        for (int i = 0; i < plaintext.length(); i++) {
            ciphertext += shiftChar(plaintext[i], rshift);
        }
        return ciphertext;
    }
    
    string encryptVigenere(string plaintext, string keyword) {
        string ciphertext = "";//empty cipher
        int j = 0;
        for (int i = 0; i < plaintext.length(); i++){
            if(isalpha(plaintext[i])) {
                ciphertext += shiftChar(plaintext[i], keyword[j] - 97);
                j++;
            }
            else {
                ciphertext += plaintext[i];//increment by 1
                
            }
            if (j == keyword.length()) {
                j = 0;
            }
        }
        return ciphertext;
    }
    
    char reverseShift(char c, int rshift) {
        char reversed_c;
        if(islower(c)) {
            reversed_c = ((c - rshift - 'z')%26 + 'z');
        }
        else if(isupper(c)) {
            reversed_c = ((c - rshift + 'A')%26 + 'A');
        }
        else {
            reversed_c = c;
        }
        return reversed_c;
    }
    
    string decryptCaesar(string plaintext, int rshift) {
        string ciphertext = ""; //empty string
        for (int i = 0; i < plaintext.length(); i++) {
            ciphertext += reverseShift(plaintext[i], rshift);
        }
        return ciphertext;
    }
    
    string decryptVigenere(string plaintext, string keyword) {
        string ciphertext = "";//empty cipher
        int j = 0;
        for (int i = 0; i < plaintext.length(); i++){
            if(isalpha(plaintext[i])) {
                ciphertext += reverseShift(plaintext[i], keyword[j] - 97);
                j++;
            }
            else {
                ciphertext += plaintext[i];//increment by 1
                
            }
            if (j == keyword.length()) {
                j = 0;
            }
        }
        return ciphertext;
    }

    
    int main()
{
	string plaintext, caesar, keyword,vigenere, decryptVi;
	int shift;
	cout << "Enter plaintext	: ";  // asks user for input
	getline(cin, plaintext);
	cout << endl;
	cout << "= Caesar =" <<endl;
	cout << "Enter shift	: "; //asks to shift
	cin >> shift;
	caesar = encryptCaesar(plaintext, shift);
	cout << "ciphertext : " << caesar << endl;  //print the encrypted word
	cout << "Decrypted	: " << decryptCaesar(caesar, shift) << endl; // print decrypted word
	cout << "= Vigenere =" << endl;
	cout << "Enter keyword	: ";	
	cin >> keyword;
	vigenere = encryptVigenere(plaintext, keyword); //calls back the encrypt function
	cout << "ciphertext	:"<< vigenere << endl;  //prints the encrypted word
	decryptVi = decryptVigenere(vigenere, keyword) ;
	cout << "Decrypted	: " <<decryptVi << endl;	
}
