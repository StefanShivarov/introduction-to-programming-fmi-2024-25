#include <iostream>

using namespace std;

const size_t MAX_SIZE = 100;

char* myStrcpy(char* dest, const char* src);
char* myStrcat(char* dest, const char* src);
size_t myStrlen(const char* str);

int main() {
    char str1[] = "Hello, World!";
    char str2[MAX_SIZE];

    cout << "[ORIGINAL] str1: " << str1 << endl;
    cout << "[AFTER STRCPY] str2: " << myStrcpy(str2, str1) << endl;
    cout << "[AFTER STRCAT] str2: " << myStrcat(str2, " Goodbye") << endl;

    cout << "Length of str1: " << myStrlen(str1) << endl;

    return 0;
}

char* myStrcpy(char* dest, const char* src) {
    char* originalDest = dest;
    
    while ((*dest = *src)) {
        ++dest;
        ++src;
    }
    
    return originalDest;
}

char* myStrcat(char* dest, const char* src) {
    char* originalDest = dest;
    
    while (*dest) {
        ++dest;
    }
    
    while ((*dest = *src)) {
        ++dest;
        ++src;
    }
    
    return originalDest;
}

size_t myStrlen(const char* str) {
    size_t length = 0;
    
    while (*str) {
        ++str;
        ++length;
    }
    
    return length;
}