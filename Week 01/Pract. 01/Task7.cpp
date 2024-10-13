#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float r = 0.0, x = 0.0, y = 0.0;

    cout << "r and (x, y): ";
    cin >> r >> x >> y;

    float distanceSquared = pow(x, 2) + pow(y, 2);
    float radiusSquared = pow(r, 2);

    if (distanceSquared < radiusSquared) {
        cout << "The point is inside the circle" << endl;
    } else if (distanceSquared == radiusSquared) {
        cout << "The point is on the circle" << endl;
    } else {
        cout << "The point is outside the circle" << endl;
    }

    return 0;
}