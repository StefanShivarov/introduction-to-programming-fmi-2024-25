#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    double x1;
    double x2;

    if (a == 0){
        x1 = ((double)-c / (double)b);
        x2 = ((double)-c / (double)b);
    }
    else
    {
        double d = b * b - 4 * a * c;
        double sqrtD = sqrt(d);

        x1 = (-b + sqrtD) / 2 / a;
        x2 = (-b - sqrtD) / 2 / a;
    }
    if (x1 != x2)
        cout << "x1 = " << x1 << endl
             << "x2 = " << x2;
    else
        cout << "x = " << x1;

    return 0;
}