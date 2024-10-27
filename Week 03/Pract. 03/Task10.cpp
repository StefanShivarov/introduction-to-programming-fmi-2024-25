#include <iostream>
#include <cmath>

using namespace std;

int sort_num(long long num);

int main() {
    long long num;
    cin >> num;

    cout << sort_num(num);

    return 0;
}

int sort_num(const long long num) {
    int sorted_num = 0, digits = 0;
    long long num_copy = num;

    for (int i = 0; i <= 9; i++) {
        while (num_copy) {
            if (num_copy % 10 == i) {
                sorted_num += i * static_cast<int>(pow(10, digits++));
            }
            num_copy /= 10;
        }
        num_copy = num;
    }

    return sorted_num;
}