/*
Name : Tanubrata Dey 
Course: CSCI 135
Instructor: Prof. Maryash
Assignment: Project 1B

This particular program takes integers from cin as input and based on positive or negative symbol sums up or subtract the numbers and give the total valu as output.
*/

#include <iostream>
using namespace std;

int main()
{
    int number;
    char symbol;
    cin >> number; //gathers from cin and input in number
    int total = number; //first number equals to total
    while (cin >> symbol >> number) {
        if (symbol == '+') {
            total = total + number; //if +, sums up the number
        }
        if (symbol == '-') {
            total = total - number;//if -, subtracts the number
        }
    }
    cout << total << endl; //performs the task and gives the total number as output
    return 0;
}
