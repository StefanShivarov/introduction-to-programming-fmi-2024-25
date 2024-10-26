#include <iostream>

using namespace std;

bool isTriangle(const int, const int, const int);

int main() {
    unsigned int n = 0;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;

        if (isTriangle(a, b, c)) {
            cout << a << " " << b << " " << c << endl;
        }
    }
}

bool isTriangle(const int a, const int b, const int c) {
    return (a > 0 && b > 0 && c > 0) && (a + b > c) && (a + c > b) && (b + c > a);
}