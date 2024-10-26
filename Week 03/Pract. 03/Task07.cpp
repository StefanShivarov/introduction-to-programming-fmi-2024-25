#include <iostream>

using namespace std;

int checkIsDigit(char);

int main() {
    char symbol;

    cout << "Enter a symbol: ";
    cin >> symbol;

    cout << checkIsDigit(symbol) << endl;

    return 0;
}


int checkIsDigit(char symbol) {
    if (symbol >= '0' && symbol <= '9') {
        return symbol % '0';
    }

    return -1;
}