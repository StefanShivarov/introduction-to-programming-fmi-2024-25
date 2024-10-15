#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int nFactorial = 1;
    for (int i = n; i > 1; i--)
    {
        nFactorial *= i;
    }
    cout << nFactorial;
}