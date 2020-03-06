/*
Name: Tanubrata Dey
Course: CSCI 135
Instructor: Prof. Maryash
Assignment: HW3

The program asks for a word as input and prints each character of the word using space as output
*/

#include <iostream>
using namespace std;
int main()
{
    string a;
    int stringLength;
    cout << "Enter a word: " << endl; //asks for a word
    
    getline(cin,a);
    stringLength = a.size(); // counts the size of string
    
   
    
    for (int i = 0; i < stringLength; i++) {
        cout << a[i] << endl; //creates a loop which prints each alphabet of the word seperatred by space
    }
    
    return 0;
}
