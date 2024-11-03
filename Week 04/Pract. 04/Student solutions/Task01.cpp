#include <iostream>

using namespace std;

void swap(int&, int&);

int main() {
    int a = 0, b = 0;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    swap(a, b);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}