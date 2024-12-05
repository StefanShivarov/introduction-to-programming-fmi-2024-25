#include <iostream>

using namespace std;

const size_t MAX_SIZE = 100;
const char CENSOR_SYMBOL = '*';

bool isEqualIgnoreCase(char a, char b);
char* replace(char* text, const char symbol, const int beg, const int end);
char* censor(char* text, char* substring);

int main() {
    char text[MAX_SIZE], substring[MAX_SIZE];

    cout << "Enter a text: ";
    cin.getline(text, MAX_SIZE);

    cout << "Enter a substring: ";
    cin.getline(substring, MAX_SIZE);

    cout << "Result: " << censor(text, substring) << endl;

    return 0;
}

bool isEqualIgnoreCase(char a, char b) {
    if (a >= 'A' && a <= 'Z') a = a + ('a' - 'A');
    if (b >= 'A' && b <= 'Z') b = b + ('a' - 'A');
    return a == b;
}

char* replace(char* text, const char symbol, const int beg, const int end) {
    for (int i = beg; i <= end; ++i) {
        text[i] = symbol;
    }

    return text;
}

char* censor(char* text, char* substring) {
    int beg, currSubstringIndex = 0;

    for (int i = 0; text[i]; ++i) {
        if (isEqualIgnoreCase(text[i], substring[currSubstringIndex])) {
            if (currSubstringIndex == 0) {
                beg = i;
            }

            ++currSubstringIndex;
        } else {
            currSubstringIndex = 0;
        }

        if (substring[currSubstringIndex] == '\0') {
            text = replace(text, CENSOR_SYMBOL, beg, i);
            currSubstringIndex = 0;
        }
    }
    
    return text;
}