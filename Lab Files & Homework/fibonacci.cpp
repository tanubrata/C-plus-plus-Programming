/*
Author: Tanubrata Dey
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab2D

We need to write a program which gives out the Fibonacci numbers from a range of 0 to less than 60
*/


#include <iostream>
using namespace std;

int main()
{
    int fib[60], i;
    fib[0] = 0;
    fib[1] = 1;
    
    cout << fib[0] << endl << fib[1] << endl; //first two numbers given
    
    for (i = 2; i < 60; i++) {
        fib[i] = fib[i-1] + fib[i-2]; // \from 2 and until 59 gives all Fibonacci numbers
        cout << fib[i] << endl;
    }

    return 0;
}
