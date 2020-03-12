

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
    ofstream out;
    out.open("hello.txt");
    
    out << "Hello, World!";
    
    out.close();
    
    ifstream in;
    in.open("hello.txt");
    
    string message;
    getline(in, message);
    
    cout << message << endl;
    in.close();
    return 0;
}
