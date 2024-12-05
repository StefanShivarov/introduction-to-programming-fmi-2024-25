#include <iostream>

using namespace std;

const size_t DIGITS = 10;

size_t getDigitsCount(const int num);
void swap(char& a, char& b);
char* getHexadecimalRepresentation(int num);

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    char* result = getHexadecimalRepresentation(num);

    cout << "Result: " << result << endl;

    delete[] result;

    return 0;
}

size_t getDigitsCount(const int num) {
    return num == 0 ? 1 : (int)log10(num) + 1;
}

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

char* getHexadecimalRepresentation(int num) {
    char* result = new char[getDigitsCount(num) + 1];
    size_t resultLength = 0;

    while (num) {
        int remainder = num % 16;

        if (remainder < DIGITS) {
            result[resultLength++] = remainder + '0';
        } else {
            result[resultLength++] = remainder - DIGITS + 'A';
        }

        num /= 16;
    }

    result[resultLength] = '\0';

    for (int i = 0; i < resultLength / 2; ++i) {
        swap(result[i], result[resultLength - i - 1]);
    }

    return result;
}