#include <iostream>

using namespace std;

const size_t MAX_SIZE = 100;

size_t myStrlen(const char* str);
char* substr(const char* str, int beg, int end);

int main() {
    char str[MAX_SIZE];
    int beg, end;

    cout << "Enter a string, a beginning index and an ending index: ";
    cin >> str >> beg >> end;

    char* result = substr(str, beg, end);

    if (result != nullptr) {
        cout << "Result: " << result << endl;
    } else {
        cout << "Invalid input!" << endl;
    }

    delete[] result;

    return 0;
}

size_t myStrlen(const char* str) {
    size_t length = 0;
    
    while (*str) {
        ++str;
        ++length;
    }
    
    return length;
}

char* substr(const char* str, int beg, int end) {
    if (beg < 0 || end < 0) {
        return nullptr;
    }

    size_t strLength = myStrlen(str);

    if (end >= strLength) {
        end = strLength - 1;
    }
    
    char* substr = new char[end - beg + 1];
    char* originalSubstr = substr;

    while (beg <= end) {
        *substr = str[beg];
        ++substr;
        ++beg;
    }

    *substr = '\0';

    return originalSubstr;
}