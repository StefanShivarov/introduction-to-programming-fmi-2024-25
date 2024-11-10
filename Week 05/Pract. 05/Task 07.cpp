#include <iostream>
using namespace std;

const size_t MAX_SIZE = 50, MIN_SIZE = 1;

bool isDataValid(size_t length);
void addElements(int arr[], size_t length);
void firstEvenThenOdd(const int arr[], int arrResult[], size_t length);
void printArray(const int arr[], size_t length);

int main() {
	size_t length = 0;
	cout << "Enter the number of values in the array(>=1 and <=50): ";
	cin >> length;

	int array[MAX_SIZE] = {};

	int arrResult[MAX_SIZE] = {};

	if (isDataValid(length)) {
		cout << "Enter the values of the array: ";
		addElements(array, length);

		firstEvenThenOdd(array, arrResult, length);

		printArray(arrResult, length);
	}
	else {
		cout << "Incorrect input data!";
	}
 
 	return 0;
}

void printArray(const int arr[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
}

void firstEvenThenOdd(const int array[], int arrResult[], size_t length) {
	size_t ind = 0;
	for (size_t j = 0;j < length;j++) {
		if (array[j] % 2 == 0) {
			arrResult[ind] = array[j];
			ind++;
		}
	}
	for (size_t j = 0;j < length;j++) {
		if (array[j] % 2 != 0) {
			arrResult[ind] = array[j];
			ind++;
		}
	}
}

bool isDataValid(size_t length) {
	if (length >= 1 && length <= 50) {
		return true;
	}
	else {
		return false;
	}
}

void addElements(int arr[], size_t length) {
	for (int i = 0;i < length;i++) {
		cin >> arr[i];
	}
}




