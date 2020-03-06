/******************************************************************************

Name: Tanubrata Dey 
Course: CSCI 136
Instructor: Minh Nguyen
Quiz : 2

Asks two number as input and prints the largest number between 2 as output

*******************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cout << "Enter the first num: ";
    cin >> x;
    cout << "Enter the second num: ";
    cin >> y;
    
    if(x > y){
        cout << "The larger of the two is " << x;
    }
	else {
        cout << "The larger of the two is " << y;
    }

    return 0;
}
