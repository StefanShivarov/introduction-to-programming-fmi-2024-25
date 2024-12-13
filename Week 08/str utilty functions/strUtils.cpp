#include <iostream>
using namespace std;

unsigned myStrlen(const char* str) {
    int counter = 0;
    while (str[counter] != '\0') {
        counter++;
    }
    return counter;
}

void myStrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void myStrcat(char* dest, const char* src) {
    unsigned len = myStrlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[len++] = src[i];
        i++;
    }
    dest[len] = '\0';
}

int main() {
    char first[20];
    cin >> first;

    cout << myStrlen(first) << endl;
    
    char second[20];
    myStrcpy(second, first);

    cout << second << endl;

    myStrcat(second, first);
    cout << second << endl;
}
