#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int powerExponent = 0;

    int powerOfTwo = 1;
    
    while (n > 0)
    {
        while (powerOfTwo*2 <= n)
        {
            powerExponent++;
            powerOfTwo *= 2;
        }
        cout << "2^" << powerExponent;
        n=n-powerOfTwo;
        powerOfTwo = 1;
        powerExponent = 0;
        if(n!=0)
        cout << " + ";
    }
}