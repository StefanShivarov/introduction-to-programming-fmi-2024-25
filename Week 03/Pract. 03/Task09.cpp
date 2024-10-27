#include <iostream>
using namespace std;

void concat(int first, int second) {
    int result = 0, counter = 0;
    int origSecond = second;
    while (second != 0) {
        second = second / 10;
        counter++;
    }
    result = first * pow(10, counter) + origSecond;
    cout << result << endl;
}

int main() {
    int first, second;
    cin >> first >> second;
    concat(first, second);
    return 0;
}