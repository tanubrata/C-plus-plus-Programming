/**********
Name: Tanubrata Dey
Course: CSCI 135
Instructor: Prof. Maryash
Task: E8.1

This program creates a program that opens a file, create data and close it, followed by further opening the file, printing its data on screen and close it.
***********/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	
	ofstream o_file; //define an ofstream variable o_file
	o_file.open("hello.txt");//open a file hello.txt 
	
	o_file << "Hello, World!";//send information to the o_file
	
	o_file.close();//close o_file
	
	ifstream i_file;//create an ifstream variable i_file
	i_file.open("hello.txt");//open hello.txt
	
	string text;
	getline(i_file, text);//get the string contents of hello.txt to i_file and print it in text
	cout << text << endl;
	
	i_file.close();//close i_file
	
	return 0;
		
}