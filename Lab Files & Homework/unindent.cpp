/******************************************************************************
Name: Tanubrata Dey
Course: CSCI 135-136
Instructor: Minh Nguyen
TAsk: Lab7A
Date: 23 March 2020
This program takes a file and removes bad indentations
*******************************************************************************/
#include <iostream>
#include<cctype>
#include<cstdlib>
using namespace std;

string removeLeadingSpaces(string line); //defining fuction for removing leading spaces

string removeLeadingSpaces(string line) {
    string new_text = "";
    bool space_found = false;
    for (int i=0; i<line.length(); i++) {
        if (!isspace(line[i])) {
            space_found = true;
        }
        if (space_found) {
            new_text = new_text + line[i];
        }
    }
    return new_text;
}

int main()
{
	string str;
	while(getline(cin, str)) {
		cout << removeLeadingSpaces(str) <<endl; //using getline to input string
	}
    return 0;
}
