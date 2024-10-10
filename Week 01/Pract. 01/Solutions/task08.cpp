#include <iostream>
using namespace std;

int main()
{
    double a;
    char action;
    double b;
    cin >> a >> action >> b;
    if (b != 0){
        switch (action)
        {
        case '*':
            cout << a * b;
            break;
        case '/':
            cout << a / b;
            break;
        case '+':
            cout << a + b;
            break;
        case '-':
            cout << a - b;
            break;
        }
    }
    else
    cout << "Error! You can't divide by 0!";


    return 0;
}