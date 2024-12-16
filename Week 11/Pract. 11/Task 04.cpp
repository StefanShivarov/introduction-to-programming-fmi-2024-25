#include <iostream>
using namespace std;

const size_t MAX_LENGTH = 100;

int countOfLowerCase(char arr[]);

int countOfUpperCase(char arr[]);

char* myStrcat(char str1[], char str2[]);

int main() {
    char str1[MAX_LENGTH] = { '\0' };
    char str2[MAX_LENGTH] = { '\0' };

    cout << "Enter the first string: ";
    cin.getline(str1, MAX_LENGTH);
    cout << "Enter the second string: ";
    cin.getline(str2, MAX_LENGTH);

    char* strRes = myStrcat(str1, str2);

    cout << "Result: " << strRes << endl;

    delete[] strRes;

    return 0;
}

int countOfLowerCase(char arr[]) {
    int count = 0;

    for (size_t i = 0;arr[i] != '\0'; i++) {
        if (arr[i] >= 'a' && arr[i] <= 'z')
            count++;
    }

    return count;
}

int countOfUpperCase(char arr[]) {
    int count = 0;

    for (size_t i = 0;arr[i] != '\0'; i++) {
        if (arr[i] >= 'A' && arr[i] <= 'Z')
            count++;
    }

    return count;
}

char* myStrcat(char str1[], char str2[]) {
    int countOfLowerCase1 = countOfLowerCase(str1);
    int countOfUpperCase2 = countOfUpperCase(str2);

    size_t resLength = countOfLowerCase1 + countOfUpperCase2 + 1;

    char* strRes = new char[resLength];

    size_t ind = 0;
    for (size_t i = 0; str1[i] != '\0'; i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            strRes[ind] = str1[i];
            ind++;
        }
    }

    for (size_t i = 0; str2[i] != '\0'; i++) {
        if (str2[i] >= 'A' && str2[i] <= 'Z') {
            strRes[ind] = str2[i];
            ind++;
        }
    }

    strRes[ind] = '\0';

    return strRes;
}