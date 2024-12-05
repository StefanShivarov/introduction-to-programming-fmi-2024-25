#include <iostream>

using namespace std;

const size_t MAX_SIZE = 100;

bool isSmallLetter(const char symbol);
char* copySmallLetters(const char* dest, char* src);

int main() {
    char str[MAX_SIZE], smallLetters[MAX_SIZE];

    cout << "Enter a string: ";
    cin.getline(str, MAX_SIZE);

    cout << "Result: " << copySmallLetters(str, smallLetters) << endl;

    return 0;
}

bool isSmallLetter(const char symbol) {
    return symbol >= 'a' && symbol <= 'z';
}

char* copySmallLetters(const char* dest, char* src) {
    char* originalSrc = src;

    while (*dest) {
        if (isSmallLetter(*dest)) {
            *src = *dest;
            ++src;
        }

        ++dest;
    }

    *src = '\0';

    return originalSrc;
}