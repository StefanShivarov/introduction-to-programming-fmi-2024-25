#include <iostream>
using namespace std;

int main()
//  `1` - Ако `x < a`
// - `2` - Ако `x = a`
// - `3` - Ако `x ∈ (a,b)`
// - `4` - Ако `x = b`
// - `5` - Ако `x > b`

{
    int a;
    int b;
    int x;
    cin >> a >> b >> x;

    int result = 0;
    if(x<a)
    result=1;
    else if(x==a)
    result = 2;
    else if(x>a && x<b)
    result = 3;
    else if(x==b)
    result = 4;
    else if(x>b)
    result = 5;

    cout << result;

    return 0;
}