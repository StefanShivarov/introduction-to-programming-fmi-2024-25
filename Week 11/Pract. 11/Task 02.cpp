#include <iostream>
using namespace std;

const size_t MIN_LENGTH = 1, MAX_LENGTH = 50;

bool isInputDataValid(size_t length);

void readArray(int arr[], size_t length);

int* shiftedArray(int arr[], size_t length, int K);

int main() {
	size_t length = 0;
	int arr[MAX_LENGTH] = {};
	int K = 0;

	cout << "Length of the array: ";
	cin >> length;

	if (isInputDataValid(length) == false) {
		cout << "Incorrect input data!";
		return -1;
	}

	readArray(arr, length);

	cout << "Enter number of shifting positions: ";
	cin >> K;
	
	int* resArr = shiftedArray(arr, length, K);

	cout << "Result: ";
	for (size_t i = 0; i < length; i++) {
		cout << resArr[i] << " ";
	}
	cout << endl;

	delete[] resArr;

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

int* shiftedArray(int arr[], size_t length, int K) {
	int* resArr = new int[length];

	for (size_t i = 0, j = length - K; i < K; i++, j++) {
		resArr[i] = arr[j];
	}

	for (size_t i = K, j = 0; i < length; i++, j++) {
		resArr[i] = arr[j];
	}

	return resArr;
}