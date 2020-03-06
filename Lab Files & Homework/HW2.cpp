   /*
   Name: Tanubrata Dey
   Course: CSCI 136
   Instructor: Prof. Maryash
   Assignment: HW2
   
   Calculates the cost to drive a car 100 miles and figure out possible distance covered with the amount of gas in tank
   */
    
#include<iostream>
using namespace std;

int main()
{
    float gas, fuelefficiency, priceofgas, costfor100mile, distancecovered;
    
    cout << "Enter amount of gas in tank: " << endl;
    cin >> gas;
    cout << "Enter fuel efficiency of car in MPG: " << endl;
    cin >> fuelefficiency;
    cout << "Enter price of gas in $: " << endl;
    cin >> priceofgas;
    
    costfor100mile = (100/fuelefficiency) * priceofgas;
    distancecovered = fuelefficiency * gas;
    cout << "cost to drive 100 miles is " << costfor100mile << endl;
    cout << "miles possible to drive is " << distancecovered << endl;
    
    return 0;
}