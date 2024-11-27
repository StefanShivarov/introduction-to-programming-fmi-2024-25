#include <iostream>
using namespace std;

void turnToNull(int* &ptr) {
    ptr = nullptr;
}

int main() {
    int num;
    cin >> num;
    int* p = &num;

    turnToNull(p);

    cout << p << '\n';
}