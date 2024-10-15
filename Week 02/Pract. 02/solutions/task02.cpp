#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int largest = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (i == 0)
            largest = a;
        if (largest < a)
            largest = a;
    }
    cout << largest;
}