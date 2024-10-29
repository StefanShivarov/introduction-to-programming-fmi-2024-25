#include <iostream>

using namespace std;

int askUser(int from, int to);

int main() {
    int from, to;
    cin >> from >> to;

    cout << askUser(from, to);
    return 0;
}

int askUser(const int from, const int to) {
    int num;
    cin >> num;

    while (num >= to || num <= from) {
        cin >> num;
    }

    return num;
}