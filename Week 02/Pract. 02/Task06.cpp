#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n = 0, k = 0;
    cin >> n >> k;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int num = k;
        for (int j = 1; j < i; j++) {
            num += k * static_cast<int>(pow(10, j));
        }
        sum += num;
    }

    cout << sum;

    return 0;
}