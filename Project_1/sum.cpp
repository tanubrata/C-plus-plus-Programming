

#include <iostream>
using namespace std;

int main()
{
    int number;
    int sum = 0;
    
	while (cin >> number)
	{
		sum = sum + number;
	}
    
    cout << sum << endl;
    return 0;
}