/******************************************************************************
Name: Tanubrata Dey
Course: CSCI 135
Instructor: Prof. Maryash
Assignment: E3.1

This program asks for a number and determines whether it is positive, negative or zero.
*******************************************************************************/
#include<iostream>
using namespace std;

int main ()
{

    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num > 0) {
        cout << num << " is a positive.";
    }

    else if (num < 0) {
        cout << num << " is a negative.";
    }

    else {
        cout << num << " is zero.";
    }

    return 0;

}
