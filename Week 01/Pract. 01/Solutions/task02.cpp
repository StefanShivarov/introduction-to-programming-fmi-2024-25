#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    int c;
    int d;
    cin >> a >> b >> c >> d;
    int sum;
    if(a%2==0)
    sum+=a;
    if(b%2==0)
    sum+=b;
    if(c%2==0)
    sum+=c;
    if(d%2==0)
    sum+=d;
    cout << sum;
    return 0;
}