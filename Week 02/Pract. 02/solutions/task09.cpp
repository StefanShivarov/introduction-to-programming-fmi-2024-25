#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            cout << " ";
        }
        for (int j = i + 1; j > 0; j--)
        {
            if (j == 1)
                cout << "*";
            else
                cout << "**";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cout << "*";
        else
            cout << "**";
    }
    cout << endl;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            if (j == 1)
                cout << "*";
            else
                cout << "**";
        }
        cout << endl;
    }
}