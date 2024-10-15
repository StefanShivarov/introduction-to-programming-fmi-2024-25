#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < i + 2; j++)
        {
            cout << j << " ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << "    ";
        }
        for (int j = i + 1; j > 0; j--)
        {
            cout << " " << j;
        }
        cout << endl;
    }
    for (int i = 1; i < n + 1; i++)
    {
        cout << i << " ";
    }
    cout << "---- ";
    for (int i = n; i > 0; i--)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            cout << j << " ";
        }
        for (int j = 0; j < i + 2; j++)
        {
            cout << "    ";
        }
        for (int j = n - 1 - i; j > 0; j--)
        {
            cout << " " << j;
        }
        cout << endl;
    }
}