#include <iostream>
using namespace std;

const size_t MIN_SIZE = 1, MAX_SIZE = 10;
const int NUMBER_OF_LETTERS = 58;//122-64

bool inputDataValidation(size_t size) {
	return (size >= MIN_SIZE && size <= MAX_SIZE);
}

void readArr(int arr[], size_t size) {
	cout << "Enter array: ";
	for (size_t i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

char* sumToLetters(int arrOne[], int arrTwo[], size_t size) {
	char* result = new char[size + 1];

	int sum = 0;
	size_t i = 0;
	for (i; i < size; i++) {
		sum = arrOne[i] + arrTwo[i];

		if (sum > 'z') {
			while (sum > 'z')
				sum -= NUMBER_OF_LETTERS;

			result[i] = (char)sum;
		}
		else if (sum < 'A') {
			while (sum < 'A')
				sum += NUMBER_OF_LETTERS;

			result[i] = (char)sum;
		}
		else {
			result[i] = (char)sum;
		}

		result[i] = (char)(sum);
	}
	result[i] = '\0';

	return result;
}

int main() {
	size_t size = MIN_SIZE;
	cout << "Enter array size(<10): ";
	cin >> size;

	if (inputDataValidation(size) == false) {
		cout << "Incorrect size!";
		return -1;
	}

	int* arrOne = new int[size];
	readArr(arrOne, size);
	int* arrTwo = new int[size];
	readArr(arrTwo, size);

	char* result = new char[size + 1];
	result = sumToLetters(arrOne, arrTwo, size);
	cout << result;

	delete[] arrOne;
	delete[] arrTwo;

	delete[] result;

	return 0;
}