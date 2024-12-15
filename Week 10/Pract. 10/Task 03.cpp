#include <iostream>
using namespace std;

const size_t MAX_LENGTH = 100;

size_t myStrlen(char arr[]);

char* reversedArr(char str[]);

int main() {
    char str[MAX_LENGTH] = { '\0' };

    cout << "Enter the first string: ";
    cin.getline(str, MAX_LENGTH);

    char* presStr = reversedArr(str);

    cout << "Reversed str: " << presStr << endl;

    delete[] presStr;
}

size_t myStrlen(char arr[]) {
    size_t length = 0;

    for (size_t i = 0;arr[i] != '\0'; i++) {
        length++;
    }

    return length;
}

char* reversedArr(char str[]) {
    size_t length = myStrlen(str);
    size_t resLength = length + 1;

    char* presStr = new char[resLength];

    int ind = 0;
    for (int i = length - 1; i >= 0; i--) {
        presStr[ind] = str[i];
        ind++;
    }

    presStr[ind] = '\0';

    return presStr;
}