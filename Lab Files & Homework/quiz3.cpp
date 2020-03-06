/******************************************************************************

Name: Tanubrata Dey 
Course: CSCI 136
Quiz : 3

Prints all numbers from 1-10 in seperate lines
*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int size = 10;
	double values[size];
    
    for (int i = 1; i <= size; i++) {//loops to print numbers from 1-10
		values[i] = i;
        cout << values[i] << endl;
    }

    return 0;
}
