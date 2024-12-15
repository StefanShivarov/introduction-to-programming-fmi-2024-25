#include <iostream>
using namespace std;

const size_t MAX_LENGTH = 100;

size_t myStrlen(char arr[]);

bool isEven(size_t value);

void myStrcpy(char dest[], char src[]);

char* modifiedStr(char str[], char pattern[]);

bool isInputDataValid(char pattern[]);

int main() {
    char str[MAX_LENGTH] = { '\0' };
    char pattern[MAX_LENGTH] = { '\0' };

    cout << "Enter a string: ";
    cin.getline(str, MAX_LENGTH);
    cout << "Enter a pattern string: ";
    cin.getline(pattern, MAX_LENGTH);

    if (!isInputDataValid(pattern)) {
        cout << "Incorrect pattern!";
        return -1;
    }

    char* pstr = modifiedStr(str, pattern);

    cout << "Result: " << pstr << endl;

    delete[] pstr;

    return 0;
}

size_t myStrlen(char arr[]) {
    size_t length = 0;

    for (size_t i = 0;arr[i] != '\0'; i++) {
        length++;
    }

    return length;
}

bool isEven(size_t value) {
    return (value % 2 == 0);
}

void myStrcpy(char dest[], char src[]) {
    size_t i = 0;

    for (i = 0;src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    dest[i] = '\0';
}

char* modifiedStr(char str[], char pattern[]) {
    size_t patLen = myStrlen(pattern);
    size_t difference = 0;

    if (isEven(patLen)) {
        difference = patLen / 2;
    }
    else {
        difference = patLen / 2 + 1;
    }

    size_t resLen = myStrlen(str) + 1;
    char* pstr = new char[resLen];

    myStrcpy(pstr, str);

    for (size_t i = 0; str[i] != '\0'; i++) {

        for (size_t k = 0; pattern[k] != ' '; k++) {
            if (str[i] == pattern[k]) {
                pstr[i] = pattern[k + difference];

                break;
            }
        }
    }

    return pstr;
}

bool isInputDataValid(char pattern[]) {
    bool space = false;

    for (size_t i = 0;pattern[i] != '\0'; i++) {
        if (pattern[i] == ' ' && space == false) {
            space = true;
        }
        else if (pattern[i] == ' ' && space == true) {
            return false;
        }
        else {
            continue;
        }
    }

    if (space == true)
        return true;
    else
        return false;
}