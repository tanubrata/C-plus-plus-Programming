/******************************************************************************

Name: Tanubrata Dey
Course: CSCI 136
Instructor: Minh Nguyen
COursework: Lab4G
Date: 24th Feb 2020

This program asks for height and width as input and output a 3x3 checkerboard

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int x, y;
    cout << "Enter width: " << endl;
    cin >> x;
    cout << "Enter height: " << endl;
    cin >> y;

    string line = "";
    for (int i = 0; i < y; i++) {
        for (int j = 0, c = '*'; j < x; j++, c = '*') {
            if (((j / 3) & 1) ^ ((i / 3) & 1)) {
                c = ' ';
                
            }
                

            line += (char)c;
        }

        line += '\n';
    }

    cout << line;
    cin.ignore();
    return 0;
}

