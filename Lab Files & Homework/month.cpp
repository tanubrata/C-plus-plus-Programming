   /*
   
   Name: Tanubrata Dey
   Course: CSCI 136
   Instructor: Minh Nguyen
   Assignment: Lab1D
   
   Asks the month and year in integers as input and interprets number of days in a month as output. */
   /*Also for the month of February it interprets number of days based on leap year. */
    
#include<iostream>
using namespace std;

int main()
{

int month, year;
cout << "Enter a year: " << endl;
cin >> year;
cout << "Enter a month (1-12): " << endl;
cin >> month;

if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
{
cout << "Number of days is 31";
}
	
else if(month == 2)
{
    if (year % 4 == 0)

    {
        if (year % 100 == 0)

        {
            if (year % 400 == 0)
                cout << "Number of days " << "29";
            else
                cout << "Number of days " << "28";

        }
        else
            cout << "Number of days " << "29";
    }
    else
        cout << "Number of days " << "28";
}
else

cout << "Number of days is 30";

return 0;
}