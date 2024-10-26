#include <iostream>

using namespace std;

char upperCase(char);
unsigned int getAsciiUppercaseOffset();

int main() {
    char symbol;

    cout << "Enter a symbol: ";
    cin >> symbol;

    cout << upperCase(symbol) << endl;
}

char upperCase(char symbol) {
    if (symbol >= 'a' && symbol <= 'z') {
        return symbol - getAsciiUppercaseOffset();
    }

    return symbol;
}

unsigned int getAsciiUppercaseOffset() {
    return 'a' - 'A';
}