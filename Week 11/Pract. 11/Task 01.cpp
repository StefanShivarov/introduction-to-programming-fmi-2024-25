#include <iostream>
using namespace std;

const size_t MIN_LENGTH = 1, MAX_LENGTH = 50;

bool isInputDataValid(size_t length);

void readArray(int arr[], size_t length);

bool canBeMultiplied(int num, int K);

int* numsMultipliedByK(int arr1[], size_t length1, int arr2[], size_t length2, int K, int& length);

int main() {
	size_t length1 = 0, length2 = 0;
	int arr1[MAX_LENGTH] = {};
	int arr2[MAX_LENGTH] = {};
	int K = 0;

	cout << "Length of the first array: ";
	cin >> length1;

	if (isInputDataValid(length1) == false) {
		cout << "Incorrect input data!";
		return -1;
	}

	readArray(arr1, length1);

	cout << "Length of the second array: ";
	cin >> length2;

	if (isInputDataValid(length2) == false) {
		cout << "Incorrect input data!";
		return -1;
	}

	readArray(arr2, length2);

	cout << "Enter special number: ";
	cin >> K;
	
	int length = 0;
	int* resultArray = numsMultipliedByK(arr1, length1, arr2, length2, K, length);

	cout << "Only the numbers multiplied by the special number: ";
	for (size_t i = 0; i < length; i++) {
		cout << resultArray[i] << " ";
	}
	cout << endl;

	delete[] resultArray;

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

bool canBeMultiplied(int num, int K) {
	if (K == 0) {
		return false;
	}
	else {
		return (num % K == 0);
	}
}

int* numsMultipliedByK(int arr1[], size_t length1, int arr2[], size_t length2, int K, int& length) {
	length = 0;

	for (size_t i = 0; i < length1; i++) {
		if (canBeMultiplied(arr1[i], K))
			length++;
	}

	for (size_t i = 0; i < length2; i++) {
		if (canBeMultiplied(arr2[i], K))
			length++;
	}

	int* arrRes = new int[length];


	int ind = 0;
	for (size_t i = 0; i < length1; i++) {
		if (canBeMultiplied(arr1[i], K)) {
			arrRes[ind] = arr1[i];
			ind++;
		}
	}

	for (size_t i = 0; i < length2; i++) {
		if (canBeMultiplied(arr2[i], K)) {
			arrRes[ind] = arr2[i];
			ind++;
		}
	}

	return arrRes;
}