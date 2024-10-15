#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    int c;
    int d;
    int e;

    int n = 0;
    while (n < 5)
    {
        int currentValue;
        cin >> currentValue;
        if (currentValue > 0)
        {
            n++;
            if (n == 1)
                a = currentValue;
            else if (n == 2)
                b = currentValue;
            else if (n == 3)
                c = currentValue;
            else if (n == 4)
                d = currentValue;
            else if (n == 5)
                e = currentValue;
        }
    }
    cout << a + b + c + d + e;
}