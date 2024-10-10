#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x;
    double y;
    double r;
    cin >> x >> y >> r;
    double r1 = sqrt(x*x + y*y);

    if(r>r1)
    cout << "In the circle";
    if(r<r1)
    cout << "Out of the circle";
    if(r==r1)
    cout << "On the circle";
    return 0;
}