/******************************************************************************

Name: Tanubrata Dey
Course: CSCI 136
Instructor: Minh Nguyen
COursework: Lab4B
Date: 24th Feb 2020

This program asks for height and width and output a checkerboard of alternating of mentioned shape
*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
int i, h, w, j;

cout << "Enter the width of the rectangle you want." << endl;
cin >> w;
cout << "Enter the height of the rectangle you want." << endl;
cin >> h; 
for (j= 0; j<h; j++){ //to repeat the number of rows.
    for (i= 0; i <w; i++) {
        if (j % 2 == 0 && i % 2 == 0 || j % 2 == 1 && i % 2 == 1){
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
