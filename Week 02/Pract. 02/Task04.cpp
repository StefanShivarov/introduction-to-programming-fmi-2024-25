#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int positive_count = 0;

    while (true) {
        if (positive_count == 5) break;

        int num = 0;
        cin >> num;

        if (num > 0) {
            positive_count++;
            sum += num;
        }
    }

    cout << sum;

    return 0;
}