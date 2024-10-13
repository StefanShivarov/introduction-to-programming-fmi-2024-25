#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a = 0, b = 0, c = 0;

    cout << "Numbers: ";
    cin >> a >> b >> c;

    int discriminant = pow(b, 2) - 4 * a * c;

    if (discriminant > 0) {
        float x1 = (-b + sqrt(discriminant)) / (2 * a);
        float x2 = (-b - sqrt(discriminant)) / (2 * a);

        cout << "Roots: " << x1 << " and " << x2 << endl;
    } else if (discriminant == 0) {
        float x = -b / (2 * a);

        cout << "Root: " << x << endl;
    } else {
        cout << "The equation has no real roots" << endl;
    }

    return 0;
}