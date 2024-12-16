#include <iostream>
using namespace std;

const size_t  MIN_LENGTH = 1, MAX_LENGTH = 50;

bool isInputDataValid(size_t length);

void readArray(int arr[], size_t length);

bool canBeMultiplied(int num, int K);

int* numsMultipliedByNeighbour(int arr[], size_t length, int& lengthRes);

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

	int lengthRes = 0;
	int* resultArray = numsMultipliedByNeighbour(arr, length, lengthRes);

	cout << "Only the numbers multiplied by their neighbour number: ";
	for (size_t i = 0; i < lengthRes; i++) {
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

int* numsMultipliedByNeighbour(int arr[], size_t length, int& lengthRes) {
lengthRes = 0;

bool firstCheck = false;
bool secondCheck = false;

	for (size_t i = 0; i < length; i++) {
		if (i == 0) {
			if (canBeMultiplied(arr[i], arr[i + 1]))
				lengthRes++;
		}
		else if (i == length - 1) {
			if (canBeMultiplied(arr[i], arr[i - 1]))
				lengthRes++;
		}
		else {
			firstCheck = canBeMultiplied(arr[i], arr[i - 1]);
			secondCheck = canBeMultiplied(arr[i], arr[i + 1]);

			if (firstCheck || secondCheck)
				lengthRes++;
		}

		firstCheck = false;
		secondCheck = false;
	}

	int* arrRes = new int[lengthRes];

	int ind = 0;
	for (size_t i = 0; i < length; i++) {
		if (i == 0) {
			if (canBeMultiplied(arr[i], arr[i + 1])) {
				arrRes[ind] = arr[i];
				ind++;
			}
		}
		else if (i == length - 1) {
			if (canBeMultiplied(arr[i], arr[i - 1])) {
				arrRes[ind] = arr[i];
				ind++;
			}
		}
		else {
			firstCheck = canBeMultiplied(arr[i], arr[i - 1]);
			secondCheck = canBeMultiplied(arr[i], arr[i + 1]);

			if (firstCheck || secondCheck) {
				arrRes[ind] = arr[i];
				ind++;
			}
		}

		firstCheck = false;
		secondCheck = false;
	}

	return arrRes;
}