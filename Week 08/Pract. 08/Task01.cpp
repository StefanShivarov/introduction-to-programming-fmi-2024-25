#include <iostream>

using namespace std;

void setToNullptr(int*& ptr);

int main() {
    int num = 10;
    int* ptr = &num;

    cout << "Before: " << ptr << endl;

    setToNullptr(ptr);

    cout << "After: " << ptr << endl;

    return 0;
}

void setToNullptr(int*& ptr) {
    ptr = nullptr;
}