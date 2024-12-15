#include <iostream>
using namespace std;

const size_t MAX_LENGTH = 100;

size_t myStrlen(char arr[]);

char* findLongestPrefix(char str1[], char str2[]);

int main() {
    char arr1[MAX_LENGTH] = { '\0' };
    cout << "Enter the first string: ";
    cin.getline(arr1, MAX_LENGTH);

    char arr2[MAX_LENGTH];
    cout << "Enter the second string: ";
    cin.getline(arr2, MAX_LENGTH);

    char* pprefix = findLongestPrefix(arr1, arr2);
    cout << "Result: " << pprefix << endl;

    delete[] pprefix;

    return 0;
}

size_t myStrlen(char arr[]) {
    size_t length = 0;

    for (size_t i = 0;arr[i] != '\0'; i++) {
        length++;
    }

    return length;
}

char* findLongestPrefix(char str1[], char str2[]) {
    size_t prefixLength = 0;

    size_t length1 = myStrlen(str1);
    size_t length2 = myStrlen(str2);

    size_t loopStop = (length1 < length2) ? length1 : length2;

    for (size_t i = 0; i < loopStop; i++) {
        if (str1[i] != str2[i]) {
            prefixLength = i;
            break;
        }
    }

    char* pprefix = new char[prefixLength + 1];

    size_t j = 0;
    for (j = 0; j < prefixLength; j++) {
        pprefix[j] = str1[j];
    }

    pprefix[j] = '\0';

    return pprefix;
}