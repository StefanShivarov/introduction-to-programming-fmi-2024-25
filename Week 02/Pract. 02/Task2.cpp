#include <iostream>

using namespace std;

int main() {
    unsigned int n = 0;
    int biggestNum = 0;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int num = 0;
        cin >> num;
        if (num > biggestNum) { biggestNum = num; }
    }

    cout << "The biggest num is: " << biggestNum << endl;

    return 0;
}