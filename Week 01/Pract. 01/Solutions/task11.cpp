#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a;
    double b;
    cout << "First number: ";
    cin >> a;
    cout << "Seconds number: " << endl;
    cin >> b;
    
    a = a + b;
    b = a - b;
    a = a - b;

    cout << "First number: " << a << endl;
    cout << "Seconds number: " << b;

    return 0;
}