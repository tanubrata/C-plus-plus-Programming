/******************************************************************************
Name: Tanubrata Dey
Course: CSCI 135-136
Instructor: Minh Nguyen
TAsk: Lab7B
Date: 23 March 2020
This program takes a file and and counts blocks opened by { & } and input real indentation
*******************************************************************************/
#include <iostream>
#include<cctype>
#include<cstdlib>
using namespace std;

string removeLeadingSpaces(string line);
int countChar(string line, char c);

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

int countChar(string line, char c) {
    int counter = 0;
    for (int i=0; i<line.length(); i++) {
        if (line[i] == c) {
            counter++;
        }
    }
    return counter;
}

void indent(string text) {
    //count number of '{' and '}'
    // number of open block = number of '{' - number of '}'
    string new_text;
    int open_block = 0;//no. of open blocks
    int opening_brace = 0;//no. of opening braces
    int closing_brace = 0;//no. of closing braces
    int indentation_level; //for indenting the closing closing_brace
    while (getline(cin,text)) {
        //go line by line of the file text
        new_text = removeLeadingSpaces(text);
        indentation_level = open_block;
        if (new_text[0] == '}') {
            indentation_level = open_block - 1;
        }
        for (int i=0; i < indentation_level; i++) {
            cout << '\t';
        }
        opening_brace = countChar(text,'{');
        closing_brace = countChar(text, '}');
        open_block = open_block + (opening_brace - closing_brace);
        cout << new_text << endl;
    }
}

int main()
{
    //removeLeadingSpaces("       int x = 1;  ");
    string bad_text;
    
    indent(bad_text);
    return 0;

}
