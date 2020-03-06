/*
Name : Tanubrata Dey 
Course: CSCI 135
Instructor: Prof. Maryash
Assignment: Project 1C

This particular program takes integers from cin as input and based on positive or negative symbol sums up or subtract the numbers and give the total value as output for multiple arithmetic equations at a time.
*/

#include <iostream>
using namespace std;

int main()
{
    int number;
    char symbol;
    bool solution = false;
    cin >> number; //gathers from cin and input in number
    int total = number; //first number equals to total
    while (cin >> symbol >> number) {
        solution = false;
        if (symbol == ';') {
			cout << total << endl;
			solution = true;
			total = number;
        }
        if (!solution) {
            if (symbol == '+') {
            total = total + number; //if +, sums up the number
            solution = true;
            }
            else if (symbol == '-') {
                total = total - number;//if -, subtracts up the number
                solution = true;
            }
        
        }
			
    }
    
    if (solution) {
        cout << total << endl; //after solving each line, performs the task and gives the total number as output
    }
    return 0;
}
