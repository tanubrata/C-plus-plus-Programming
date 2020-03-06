/*
Name : Tanubrata Dey 
Course: CSCI 135
Instructor: Prof. Maryash
Assignment: Project 1D

This program performs addition or subtraction including squaring if '^' is present and solves multiple solution at a time.
*/

#include <iostream>
using namespace std;

int main() {
	
	int number = 0;
	int result=0;
	char symbol; //for right hand operator
	char prev_symbol = '+'; //for left hand operator before
	cin >> number;
	
	while (cin >> symbol) { // creates loop until no more operator is found
		if (symbol == '^'){	// does square of the number when '^'
			number = number*number;
			cin >> symbol;			
		}
		if (prev_symbol == '+'){		
			result += number;
		} else if (prev_symbol == '-') {
			result -= number;
		}
		prev_symbol = symbol;
		cin >> number;
		if (prev_symbol == ';'){
			cout << result << endl;
			result = 0;
			prev_symbol = '+';
		}
	}
	
    return 0;
}