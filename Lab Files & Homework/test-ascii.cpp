/******************************************************************************

Name: Tanubrata Dey
Course: CSCI 136
Instructor: Minh Nguyen
Task: Lab6A

This program asks to input a string and output its ascii number
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;
    cout << "ENter a message: ";
    getline(cin, text);
    for (int i = 0; i < text.length(); i++) {
        cout << text[i] <<  " " << int(text[i]) << endl;
    }
    
    return 0;
}
