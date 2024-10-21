#include <iostream>
using namespace std;

int main() {
    int n, a = 1;
    cin >> n;
    for (int i = n; i > 0; i--) {
        a = a * i;
    }
    cout << a << endl;
    return 0;
}
