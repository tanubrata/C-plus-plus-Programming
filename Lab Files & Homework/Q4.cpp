/******************************************************************************

Name: Tanubrata Dey
Course: CSCI 136
Instructor: Minh Nguyen
COursework: Quiz 4
Date: 24th Feb 2020

This program opens a filestream data.txt which contains name of colors and RGB code and reads each line and print them on screen as ouput.

*******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("data.txt");
	string color, RGB, line;
	getline(fin,line);
	while (fin >> color >> RGB) {
	    cout << color << " " << RGB << endl;
	}
	fin.close();
	return 0;
}

