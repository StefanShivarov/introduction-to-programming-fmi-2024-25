#include <iostream>
using namespace std;

bool isLetter(int code);

int numbersOfLetters(int arr1[], int arr2[], int N);

char* lettersFromTheSumOfTwoArrs(int arr1[], int arr2[], int N);

int main() {
    size_t N = 0;
    cout << "Enter the number of values in each array: ";
    cin >> N;

    int* parr1 = new int[N];
    cout << "Enter the values: ";
    for (size_t i = 0; i < N; i++) {
        cin >> parr1[i];
    }

    int* parr2 = new int[N];
    cout << "Enter the values: ";
    for (size_t i = 0; i < N; i++) {
        cin >> parr2[i];
    }

    char* parr = lettersFromTheSumOfTwoArrs(parr1, parr2, N);
    cout << "Result: " << parr;

    delete[] parr;
    delete[] parr1;
    delete[] parr2;

    return 0;
}

bool isLetter(int code) {
    return ((code >= 'a' && code <= 'z') || (code >= 'A' && code <= 'Z'));
}

int numbersOfLetters(int arr1[], int arr2[], int N) {
    int count = 0;

    int sumOfTwoElsSameInd = 0;
    for (size_t i = 0; i < N; i++) {
        sumOfTwoElsSameInd = arr1[i] + arr2[i];

        if (isLetter(sumOfTwoElsSameInd)) {
            count++;
        }
    }

    return count;
}

char* lettersFromTheSumOfTwoArrs(int arr1[], int arr2[], int N) {
    int lengthArr = numbersOfLetters(arr1, arr2, N) + 1;
    char* parr = new char[lengthArr];

    int ind = 0;
    int sumOfTwoElsSameInd = 0;
    for (size_t i = 0; i < N; i++) {
        sumOfTwoElsSameInd = arr1[i] + arr2[i];

        if (isLetter(sumOfTwoElsSameInd)) {
            parr[ind] = (char)sumOfTwoElsSameInd;
            ind++;
        }
    }

    parr[ind] = '\0';

    return parr;
}