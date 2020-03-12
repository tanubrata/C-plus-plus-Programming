/******************************************************************************

Name: Tanubrata Dey
Course: CSCI 136
Instructor: Minh Nguyen
Task: Lab6C

This program asks to input a string and vignere cipher
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
    
    char reverseShiftChar(char c, int rshift) {
        char decrypted_c;
        if(islower(c)) {
            decrypted_c = ((c - 'a') + 26) - rshift + 'a';
        }
        else if(isupper(c)) {
            decrypted_c = ((c - 'A') + 26) - rshift + 'A';
        }
        else {
            decrypted_c = c;
        }
        return decrypted_c;
    }
    
    
    

    
    int main() {
        string plaintext;
        string keyword;
        cout << "Enter plaintext: ";
        getline(cin, plaintext);
        cout << "Enter keyword: ";
        getline(cin, keyword);
        cout << encryptVigenere(plaintext, keyword);
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    