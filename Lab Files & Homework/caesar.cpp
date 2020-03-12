/******************************************************************************

Name: Tanubrata Dey
Course: CSCI 136
Instructor: Minh Nguyen
Task: Lab6B

This program asks to input a string and output caesar cipher with spaces
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
    
    int main() {
        string plaintext;
        int shift;
        cout << "Enter plaintext: ";
        getline(cin, plaintext);
        cout << "Enter shift: ";
        cin >> shift;
        cout << encryptCaesar(plaintext, shift);
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    