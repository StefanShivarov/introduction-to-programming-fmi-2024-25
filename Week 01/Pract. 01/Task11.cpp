#include <iostream>

using namespace std;

int main() {
    float num1 = 0.0, num2 = 0.0;

    cout << "First number: "; cin >> num1;
    cout << "Second number: "; cin >> num2;

    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    cout << "First number: " << num1 << endl;
    cout << "Second number: " << num2 << endl;

    return 0;
}