#include <iostream>

using namespace std;

unsigned int ascii(char);

int main() {
    char symbol;
    
    cout << "Enter a symbol: ";
    cin >> symbol;
    
    cout << "ASCII code of " << symbol << " is " << ascii(symbol) << endl;
    
    return 0;
}

unsigned int ascii(char symbol) {
    return symbol;
}