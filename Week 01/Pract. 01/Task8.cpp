#include <iostream>

using namespace std;

int main() {
    float num1 = 0.0, num2 = 0.0, res = 0.0;
    char operation;

    cout << "Input: ";
    cin >> num1 >> operation >> num2;

    switch (operation) {
    case '+':
        res = num1 + num2;
        break;
    case '-':
        res = num1 - num2;
        break;
    case '*':
        res = num1 * num2;
        break;
    case '/':
        if (num2 == 0) {
            cout << "Error! You can't divide by 0!" << endl;
            return 1;
        }
        res = num1 / num2;
        break;
    default:
        cout << "Invalid operation" << endl;
        return 1;
    }

    cout << "Result: " << res << endl;

    return 0;
}