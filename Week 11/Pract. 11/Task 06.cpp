#include <iostream>
using namespace std;

const size_t MIN_LENGTH = 1, MAX_LENGTH = 150;
const char INITIAL_CHAR = '\0';

bool isInputDataValid(size_t length);

void readArray(int arr[], size_t length);

size_t myStrlen(char str[]);

char* modifiedArray(char str[], int arr[], size_t arrLength, char S);

int main() {
    char str[MAX_LENGTH] = { '\0' };
   
    cout << "Enter a string: ";
    cin.getline(str, MAX_LENGTH);

    size_t lengthNumArr = 0;
    cout << "Enter the length of the number array: ";
    cin >> lengthNumArr;

    if (!(isInputDataValid(lengthNumArr))) {
        cout << "Incorrect input data!";
        return -1;
    }

    int arr[MAX_LENGTH] = { 0 };
    readArray(arr, lengthNumArr);

    char S = INITIAL_CHAR;
    cout << "Enter the special symbol: ";
    cin >> S;

    char* strRes = modifiedArray(str, arr, lengthNumArr, S);;

    cout << "Result: " << strRes << endl;

    delete[] strRes;

    return 0;
}

bool isInputDataValid(size_t length) {
    return (length >= MIN_LENGTH && length <= MAX_LENGTH);
}

void readArray(int arr[], size_t length) {
    cout << "Enter values of array: ";
    for (size_t i = 0; i < length; i++) {
        cin >> arr[i];
    }
}

size_t myStrlen(char str[]) {
    size_t length = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        length++;
    }

    return length;
}   

char* modifiedArray(char str[], int arr[], size_t arrLength, char S) {
    size_t strLength = myStrlen(str);
    char* resArr = new char[strLength + arrLength + 1];

    int ind = 0;
    for (size_t i = 0; str[i] != '\0'; i++) {

        for (size_t j = 0; j < arrLength; j++) {
            if (i == arr[j]) {
                resArr[ind] = S;
                ind++;
                break;
            }
        }

        resArr[ind] = str[i];
        ind++;
    }

    resArr[ind] = '\0';

    return resArr;
}