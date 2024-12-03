#include <iostream>

using namespace std;

const size_t MAX_SIZE = 100;
const unsigned int DIGITS_COUNT = 10;
const unsigned int MAX_BASE = 36;

bool isSizeValid(const unsigned int size);
bool isBaseValid(const unsigned int base);
bool isNumeralValid(const char numeral);
int readNumber(char number[], const unsigned int n);
void printNumber(const char number[], const unsigned int n);
int getNumeralValue(const char numeral);
char toAsciiValue(const int value);
int convertToDecimal(const char number[], const unsigned int n, const unsigned int k);
void convertToKBase(const int decimal, const unsigned int k, char number[], unsigned int &n);

int main() {
    unsigned int n;
    cout << "N: ";
    cin >> n;

    if (!isSizeValid(n)) {
        cout << "Invalid size!" << endl;
        return 0;
    }

    unsigned int k;
    cout << "K: ";
    cin >> k;

    if (!isBaseValid(k)) {
        cout << "Invalid base!" << endl;
        return 0;
    }

    char number[MAX_SIZE];

    if (1 == readNumber(number, n)) {
        cout << "Invalid numeral!" << endl;
        return 0;
    }

    int decimal = convertToDecimal(number, n, k);

    char newNumber[MAX_SIZE] = {0};
    unsigned int newNumberSize;

    convertToKBase(decimal - 1, k, newNumber, newNumberSize);

    printNumber(newNumber, newNumberSize);

    return 0;
}

bool isSizeValid(const unsigned int size) {
    return size > 0 && size <= MAX_SIZE;
}

bool isBaseValid(const unsigned int base) {
    return base > 0 && base <= MAX_BASE;
}

bool isNumeralValid(const char numeral) {
    return (numeral >= '0' && numeral <= '9') || (numeral >= 'A' && numeral <= 'Z') || (numeral >= 'a' && numeral <= 'z');
}

int readNumber(char number[], const unsigned int n) {
    for (int i = 0; i < n; ++i) {
        char numeral;
        cin >> numeral;

        if (!isNumeralValid(numeral)) {
            return 1;
        }

        number[i] = numeral;
    }

    return 0;
}

void printNumber(const char number[], const unsigned int n) {
    for (int i = 0; i < n; ++i) {
        cout << number[i];
    }

    cout << endl;
}

int getNumeralValue(const char numeral) {
    if (numeral >= '0' && numeral <= '9') {
        return numeral - '0';
    } 
    
    if (numeral >= 'A' && numeral <= 'Z') {
        return numeral - 'A' + DIGITS_COUNT;
    } 
    
    return numeral - 'a' + DIGITS_COUNT;
}

char toAsciiValue(const int value) {
    if (value < DIGITS_COUNT) {
        return value + '0';
    }

    return value - DIGITS_COUNT + 'A';
}

int convertToDecimal(const char number[], const unsigned int n, const unsigned int k) {
    int decimal = 0;
    int power = 1;

    for (int i = n - 1; i >= 0; --i) {
        decimal += getNumeralValue(number[i]) * power;
        power *= k;
    }

    return decimal;
}

void convertToKBase(int decimal, const unsigned int k, char number[], unsigned int &n) {
    n = 0;

    while (decimal > 0) {
        int remainder = decimal % k;
        decimal /= k;
        number[n++] = toAsciiValue(remainder);
    }

    for (int i = 0; i < n / 2; ++i) {
        swap(number[i], number[n - i - 1]);
    }
}