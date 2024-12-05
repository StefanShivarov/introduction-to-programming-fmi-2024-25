#include <iostream>

using namespace std;

const size_t MAX_SIZE = 100;

char* replace(char* str, const char x, const char a, const char b);

int main() {
    char str[MAX_SIZE], x, a, b;

    cout << "Enter a string: ";
    cin.getline(str, MAX_SIZE);

    cout << "Enter three characters (x, a, b): ";
    cin >> x >> a >> b;

    cout << "Result: " << replace(str, x, a, b) << endl;

    return 0;
}

char* replace(char* str, const char x, const char a, const char b) {
    char* originalStr = str;

    size_t occurrences = 0;

    while (*str) {
        if (*str == x) {
            ++occurrences;

            if (occurrences % 2 == 0) {
                *str = a;
            } else {
                *str = b;
            }
        }

        ++str;
    }

    return originalStr;
}