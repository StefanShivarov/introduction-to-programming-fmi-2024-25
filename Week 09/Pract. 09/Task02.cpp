#include <iostream>
using namespace std;

bool isSmallLetter(char c) {
    return c >= 'a' && c <= 'z';
}

void storeSmallLettersOnly(char* dest, const char* src) {
    int srcIndex = 0, destIndex = 0;
    while (src[srcIndex] != '\0') {
        if (isSmallLetter(src[srcIndex])) {
            dest[destIndex++] = src[srcIndex];
        }
        srcIndex++;
    }
    dest[destIndex] = '\0';
}

int main() {
    char str[50];
    cin >> str;

    char result[50];
    storeSmallLettersOnly(result, str);

    cout << result;
}