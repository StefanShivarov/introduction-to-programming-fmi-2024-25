#include <iostream>
using namespace std;

int main()
{
    cout << "Dividend: ";
    int dividend;
    cin >> dividend;
    cout << "Divisor: ";
    int divisor;
    cin >> divisor;

    int quotient = dividend / divisor;
    int remainder = dividend % divisor;
    cout << "The quotient of the division is : " << quotient << endl;
    cout << "The remainder of the division is : " << remainder << endl;

    return 0;
}