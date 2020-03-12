/*
Name: Tanubrata Dey
Instructor: Prof. Maryash
Assignment: 5-14

This program asks any 2 integers and sort them based on their size value from low to high
*/

#include <iostream> 
#include <algorithm> 
using namespace std;
 
void sort2(int& a, int& b)
{
   if ( b <= a )
   {
      int temporary = a;
      a = b;
      b = temporary;
   }
   else {
   	a = a;
	b = b;
   }
   
}

int main() {
	int x, y;
	cout << "Enter 1st number: ";
	cin >> x;
	cout << "Enter 2nd number: ";
	cin >> y;
	sort2(x, y);
	cout << x << ", " << y << endl;
	
}