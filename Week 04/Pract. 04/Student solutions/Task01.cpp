#include <iostream>

using namespace std;

void swap(int& a, int& b);

int main() {
    int a, b;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    swap(a, b);

    cout << "a: " << a << endl;
    cout << "b: " << b;

    return 0;
}

void swap(int& a, int& b) {
    const int temp = a;
    a = b;
    b = temp;
}