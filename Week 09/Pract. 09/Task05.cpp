#include <iostream>

using namespace std;

const size_t MAX_SIZE = 100;

char* getLongesCommonPrefix(const char* str1, const char* str2, const char* str3);

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE], str3[MAX_SIZE];

    cout << "Enter three strings: " << endl;
    cin.getline(str1, MAX_SIZE);
    cin.getline(str2, MAX_SIZE);
    cin.getline(str3, MAX_SIZE);

    char* result = getLongesCommonPrefix(str1, str2, str3);

    cout << "Result: " << result << endl;

    delete[] result;

    return 0;
}

char* getLongesCommonPrefix(const char* str1, const char* str2, const char* str3) {
    char* result = new char[MAX_SIZE];
    char* originalResult = result;
    
    while (*str1 && *str2 && *str3 && *str1 == *str2 && *str2 == *str3) {
        *result = *str1;
        ++result;
        ++str1;
        ++str2;
        ++str3;
    }

    *result = '\0';

    return originalResult;
}