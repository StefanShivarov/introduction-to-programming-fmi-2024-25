#include <iostream>

using namespace std;

double calculate(const int a, const int b, char action);

int main() {
    int a, b;
    char action;
    cin >> a >> b >> action;

    cout << calculate(a, b, action);

    return 0;
}

double calculate(const int a, const int b, char action) {
    switch (action) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                cout << "Division by zero!";
                return -1;
            }
            return static_cast<double>(a) / b;
        default:
            cout << "Invalid action!";
    }
    return -1;
}
