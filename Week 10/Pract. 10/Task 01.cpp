#include <iostream>
using namespace std;

const size_t MAX_LENGTH = 100;

size_t myStrlen(char arr[]);

char* myStrcat(char str1[], char str2[]);

int main() {
    char str1[MAX_LENGTH] = { '\0' };
    char str2[MAX_LENGTH] = { '\0' };

    cout << "Enter the first string: ";
    cin.getline(str1, MAX_LENGTH);
    cout << "Enter the second string: ";
    cin.getline(str2, MAX_LENGTH);

    char* pstr = myStrcat(str1, str2);

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

char* myStrcat(char str1[], char str2[]) {
    size_t length1 = myStrlen(str1);
    size_t length2 = myStrlen(str2);

    size_t resLength = length1 + length2 + 1;

    char* pstr = new char[resLength];

    int ind = 0;

    for (size_t i = 0; str1[i] != '\0'; i++) {
        pstr[ind] = str1[i];
        ind++;
    }

    for (size_t i = 0; str2[i] != '\0'; i++) {
        pstr[ind] = str2[i];
        ind++;
    }

    pstr[ind] = '\0';

    return pstr;
}