#include <iostream>

using namespace std;

int return_num(char symbol);

int main() {
    char symbol;
    cin >> symbol;

    cout << return_num(symbol);

    return 0;
}

int return_num(const char symbol) {
    if (symbol >= 48 && symbol <= 57) return static_cast<int>(symbol) - 48;
    return -1;
}