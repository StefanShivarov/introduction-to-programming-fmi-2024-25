#include <iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;
    int a = number%10;
    int b = number/10%10;
    int c = number/10/10%10;
    int d = number/10/10/10%10;
    int sum = a+b+c+d;
    double avg = (double)(a+b+c+d)/4;
    int p = a*b*c*d;
    cout << "sum=" << sum << " p=" << p << " avg=" << avg;
    return 0;
}