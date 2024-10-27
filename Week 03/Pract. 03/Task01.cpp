#include <iostream>
using namespace std;

int calculate(const int a, const int b, char action) {
    int result = 0;
    switch (action) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0) cout << "Error" << endl;
            else result = a / b;
            break;
        default:
            cout << "Error" << endl;
    }
    return result;
}

int main() {
    int a, b;
    char act;
    cin >> a >> b >> act;
    cout << "Result: " << calculate(a, b, act) << endl;

    return 0;
}
