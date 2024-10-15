#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    int c;

    int n = 0;
    while (n < 3)
    {
        int currentValue;
        cin >> currentValue;
        if (currentValue < 0)
        {
            n++;
            if (n == 1)
                a = currentValue;
            else if (n == 2)
                b = currentValue;
            else if (n == 3)
                c = currentValue;
        }
    }
    int lowestNumber = a;
    if (b < lowestNumber)
        lowestNumber = b;
    if (c < lowestNumber)
        lowestNumber = c;

    cout << lowestNumber;
}