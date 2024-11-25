#include <iostream>

using namespace std;

const int MIN_SIZE = 1, MAX_SIZE = 32;

bool isInputDataValid(int size);

void printError();

void addElementsToArray(char arr[], int N);

long myPow(int num, int power);

void printSubsets(char arr[], int size);

int intToChar(int num);

void fromDecimalToK(char result[], long dec, int K, int& count);

int main() {
    int size = MIN_SIZE;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (isInputDataValid(size)) {
        char array[MAX_SIZE] = {};
        addElementsToArray(array, size);

        printSubsets(array, size);
    }
    else {
        printError();
    }

    return 0;
}

bool isInputDataValid(int size) {
    return (size >= MIN_SIZE && size <= MAX_SIZE);
}

void printError() {
    cout << "Error!";
}

void addElementsToArray(char arr[], int N) {
    cout << "Enter elements of array: ";

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

long myPow(int num, int power) {
    long powNum = 1;

    if (power == 0) {
        return 1;
    }

    for (int i = 1; i <= power; i++) {
        powNum *= num;
    }

    return powNum;
}

void printSubsets(char array[], int size) {
    int numberOfSubsets = myPow(2, size);

    for (int i = 0; i < numberOfSubsets; i++) {
        char subset[MAX_SIZE] = {};
        int subsetInd = 0;

        char iToBinary[MAX_SIZE] = {};
        int iToBinarySize = 0;
        fromDecimalToK(iToBinary, i, 2, iToBinarySize);

        for (int j = 0; j < size; j++) {
            if (iToBinary[j] == '1') {
                subset[subsetInd] = array[j];
                subsetInd++;
            }
        }

        cout << "{ ";
        for (int i = 0; i < subsetInd;i++) {
            cout << subset[i] << " ";
        }
        cout << "}" << endl;
    }
}

int intToChar(int num) {
    if (num >= 0 && num <= 9) {
        return ((char)(num + '0'));
    }
    else if (num >= 10 && num <= 36) {
        return ((char)(num - 10 + 'A'));
    }
    else {
        return -1;
    }
}

void fromDecimalToK(char result[], long dec, int K, int& count) {

    for (size_t i = 0; dec > 0; i++) {
        result[i] = intToChar(dec % K);
        dec /= K;

        count++;
    }
}