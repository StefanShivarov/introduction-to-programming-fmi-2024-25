#include <iostream>
using namespace std;

unsigned myStrlen(const char* str) {
    int counter = 0;
    while (str[counter] != '\0') {
        counter++;
    }
    return counter;
}

void substr(char* dest, const char* src, unsigned start, unsigned end) {
    unsigned length = myStrlen(src);
    int smaller = length < end ? length - 1 : end;
    int index = 0;
    for (int i = start; i <= smaller; i++) {
        dest[index++] = src[i];
    }
    dest[index] = '\0';
}

int main() {
    char str[50];
    cin >> str;

    int start, end;
    cin >> start >> end;

    char result[50];
    substr(result, str, start, end);

    cout << result;
}