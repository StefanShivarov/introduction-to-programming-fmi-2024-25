#include <iostream>
using namespace std;

const size_t MAX_LENGTH = 100, NUMBER_ASCII_CODES = 128;

char* identicalStr(char str[]);

int main() {
    char str[MAX_LENGTH] = { '\0' };

    cout << "Enter the first string: ";
    cin.getline(str, MAX_LENGTH);

    char* pstr = identicalStr(str);

    cout << "Result: " << pstr << endl;

    delete[] pstr;

    return 0;
}

char* identicalStr(char str[]) {
    bool mapArr[NUMBER_ASCII_CODES] = { 0 };

    int asciiCode = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        asciiCode = (int)(str[i]);

        if (mapArr[asciiCode] == 0) {
            mapArr[asciiCode] = 1;
        }
    }

    int countOfIdentical = 0;
    for (size_t i = 0; i < NUMBER_ASCII_CODES; i++) {
        if (mapArr[i] == 1)
            countOfIdentical++;
    }

    char* pstr = new char[countOfIdentical + 1];

    /*int ind = 0;
    for (size_t i = 0; i < NUMBER_ASCII_CODES; i++) {
        if (mapArr[i] == 1) {
            pstr[ind] = (char)(i);

            ind++;
        }
    }*/


    int ind = 0;
    for (size_t i = 0; str[i] != '\0'; i++) {
        asciiCode = (int)(str[i]);

        if (mapArr[asciiCode] == 1) {
            pstr[ind] = (char)(asciiCode);
            mapArr[asciiCode] = 0;

            ind++;
        }
    }

    pstr[ind] = '\0';

    return pstr;
}