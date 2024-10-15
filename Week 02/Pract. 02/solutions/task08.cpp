#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }
        cout << " | ";
        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}