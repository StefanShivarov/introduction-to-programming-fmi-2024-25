#include <iostream>

using namespace std;

const size_t MIN_LENGTH = 1, MAX_LENGTH = 10;

bool isInputDataValid(size_t length);

void readArray(int* ptr, size_t length);

bool isPalindrome(int* arr, size_t length, size_t ind);

bool isArrayTwoPalindromes(int* arr, size_t length);

int main() {
	size_t length = 0;
	cout << "Enter array size: ";
	cin >> length;

	if (!isInputDataValid(length)) {
		cout << "Incorrect input data!" << endl;
		return -1;
	}

	int array[MAX_LENGTH] = {};
	int* ptrArr = array;

	cout << "Enter the elements of the array: ";
	readArray(ptrArr, length);

	if (isArrayTwoPalindromes(array,length)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
}

bool isInputDataValid(size_t length) {
	return(length >= MIN_LENGTH && length <= MAX_LENGTH);
}

void readArray(int* ptr, size_t length) {
	for (size_t i = 0; i < length; i++) {
		cin >> *ptr;
		ptr++;
	}
}

bool isPalindrome(int* arr, size_t length, size_t ind) {
	for (size_t i = ind, j = length - 1; i < j; i++, j--) {
		if (arr[i] != arr[j]) {
			return false;
		}
	}

	return true;
}

bool isArrayTwoPalindromes(int* arr, size_t length) {
	size_t ind = 0;
	size_t currentLength = 1;
	bool isFirstPartPalindrome = false;
	bool isSecondPartPalindrome = false;

	for (size_t k = 0; currentLength < length; k++) {

		if (isPalindrome(arr, currentLength, ind)) {
			isFirstPartPalindrome = true;

			ind = currentLength;
			if (isPalindrome(arr, length, ind)) {
				isSecondPartPalindrome = true;
			}
		}

		if (isFirstPartPalindrome && isSecondPartPalindrome) {
			return true;
		}

		isFirstPartPalindrome = false;
		isSecondPartPalindrome = false;

		currentLength++;
		ind = 0;
	}

	return false;
}