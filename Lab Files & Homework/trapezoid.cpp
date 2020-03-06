/******************************************************************************

Name: Tanubrata Dey
Course: CSCI 136
Instructor: Minh Nguyen
COursework: Lab4F
Date: 24th Feb 2020

This program asks for height and width as input and output an iverted trapezium

*******************************************************************************/
#include <iostream>
using namespace std;


int main()
{    
    int rows, width, height, spaces, stars; // declare values

    cout << "enter width" << endl;
    cin >> width;

    cout << "enter height" << endl;
    cin >> height;
    if (width-height < width/2) {//condition for impossible values
        cout << "Impossible!";
    }
    else {
        for (int row = 0; row < height; ++row) {
            for (int col = height + row; col > 0; --col) {//loop for spaces

            cout << " ";
            }

            for (int col = 0; col < (width - 2 * row); ++col) {//loop for stars
                cout << "*";

                spaces += 1;
                stars -= 2;
            }
            cout << endl;
        }
    }
    
    return 0;
}
    
