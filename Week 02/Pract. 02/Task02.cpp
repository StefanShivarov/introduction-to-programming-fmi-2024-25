#include <iostream>

using namespace std;

int main() {
    unsigned int count = 0;
    cin >> count;

    int largest = 0;
    for (int i = 0; i < count; i++) {
        int current = 0;
        cin >> current;

        if (largest < current) largest = current;
    }

    cout << largest;

    return 0;
}
