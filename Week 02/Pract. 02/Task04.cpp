#include <iostream>
using namespace std;

int main() {
    int n = 0, sum = 0;
    while (n < 5) {
        int k;
        cin >> k;

        if (k > 0) {
            n++;
            sum += k;
        }
    }

    cout << sum << endl;

    return 0;
}
