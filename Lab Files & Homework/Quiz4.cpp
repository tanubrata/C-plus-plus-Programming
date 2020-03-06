/******************************************************************************

Name: Tanubrata Dey
Course: CSCI 136
Instructor: Minh Nguyen
COursework: Quiz 4
Date: 24th Feb 2020

This program opens a filestream data.txt which contains name of colors and RGB code and reads each line and print them on screen as ouput.
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

int main()
{
    string names_of_colors, RGB;
    
    ifstream fin("data.txt");
    if (fin.fail()) {
    		cerr << "File cannot be opened for reading." << endl;
    		exit(1); // exit if failed to open the file
	}
	
	

    
    while (fin >> names_of_colors >> RGB) {
        fin.ignore(INT_MAX, '\n');
        cout << names_of_colors << " " << RGB << endl;
    }
    fin.close();
    return 0;
}
