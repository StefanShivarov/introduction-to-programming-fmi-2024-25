#include <iostream>

using namespace std;

void print_triangle_sides(int n);
bool are_triangle_sides(int a, int b, int c);

int main() {
    int n;
    cin >> n;

    print_triangle_sides(n);

    return 0;
}

void print_triangle_sides(const int n) {
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (are_triangle_sides(a, b, c)) cout << a << " " << b << " " << c << endl;
    }
}

bool are_triangle_sides(const int a, const int b, const int c) {
    return (a + b > c) && (b + c > a) && (a + c > b) && a > 0 && b > 0 && c > 0;
}