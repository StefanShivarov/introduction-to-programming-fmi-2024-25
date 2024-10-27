#include <iostream>
using namespace std;

void capLetter(char symbol) {
    // symbol = toupper(symbol);

    if(symbol >= 'a' && symbol <= 'z') {
        symbol = symbol - ('a'-'A');
    }
    cout << symbol;
}
int main() {
    char symbol;
    cin >> symbol;
    capLetter(symbol);
    return 0;
}