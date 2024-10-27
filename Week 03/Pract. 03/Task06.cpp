#include <iostream>

using namespace std;

char capitalize(char symbol);

int main() {
    char symbol;
    cin >> symbol;

    cout << capitalize(symbol);

    return 0;
}

char capitalize(const char symbol) {
    if (symbol >= 97 && symbol <= 123) {
        return static_cast<char>(symbol - 32);
    }

    return symbol;
}