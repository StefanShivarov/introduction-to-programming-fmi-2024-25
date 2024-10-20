#include <iostream>

using namespace std;

int main() {
    unsigned int n = 0;
    int sum = 0;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int num = 0;
        cin >> num;
        sum += num;
    }

    cout << "The sum is: " << sum << endl;

    return 0;
}