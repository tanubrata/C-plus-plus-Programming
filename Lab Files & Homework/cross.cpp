/******************************************************************************

Name: Tanubrata Dey
Course: CSCI 136
Instructor: Minh Nguyen
COursework: Lab4C
Date: 24th Feb 2020

This program asks for size and output a cross of mentioned shape
*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
int i, size, j;

cout << "Enter the size:" << endl;
cin >> size;
 
for (j= 0; j<size; j++){ //to repeat the number of rows.
    for (i= 0; i < size; i++) {
        if (j == i || i == (size - j - 1) ){
            cout << "*";
        }
    else {
        cout << " ";
    }
    
}
cout << endl;


}

return 0;

}
