#include <iostream>
using namespace std;

int isDigit(char symbol) {
    if (symbol >= '0' && symbol <= '9') {
        return symbol - '0';
    } else { return -1; }
}

int main() {
    char symbol;
    cin >> symbol;
    cout << isDigit(symbol) << endl;
    return 0;
}
