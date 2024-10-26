#include <iostream>

using namespace std;

int calculate(const int, const int, char);

int main() {
    int a = 0, b = 0;
    char action;

    cout << "Enter two numbers and an action (+, -, *, /) between them: ";
    cin >> a >> action >> b;
    
    cout << "Result: " << calculate(a, b, action) << endl;
    
    return 0;  
}

int calculate(const int a, const int b, char action) {
    switch (action) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}