#include <iostream>

using namespace std;

unsigned short ascii(char symbol);

int main() {
    char symbol;
    cin >> symbol;

    cout << ascii(symbol);

    return 0;
}

unsigned short ascii(char symbol) {
    return static_cast<int>(symbol);
}