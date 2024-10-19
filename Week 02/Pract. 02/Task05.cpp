#include <iostream>

using namespace std;

int main() {
    int smallest = 0;
    int negative_in_a_row_count = 0;

    while (true) {
        if (negative_in_a_row_count == 3) break;

        int num = 0;
        cin >> num;

        if (num < 0) {
            negative_in_a_row_count++;
            if (smallest > num) smallest = num;
        } else {
            negative_in_a_row_count = smallest = 0;
        }
    }

    cout << smallest;

    return 0;
}