#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int k, n;
    cin >> n >> k;

    int currentNumber = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        currentNumber += pow(10, i) * k;
        sum += currentNumber;
    }
    cout << sum;
}