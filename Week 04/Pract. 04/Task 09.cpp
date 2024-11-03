#include <iostream>

using namespace std;

const size_t arraySize = 50;
const size_t minArraySize = 1;

void addElementsToArray(double*, int);
bool isInputDataCorrect(int);
void arrayInAscendingOrder(double*, int);
void addElementsToArrayAndSortThem(double*, int);
void printArray(double*, int);

int main() {
	int countOfElements = 0;
	double array[arraySize];
	cout << "Enter the number of values in the array: ";
	cin >> countOfElements;

	addElementsToArrayAndSortThem(array, countOfElements);
 
  return 0;
}

void addElementsToArrayAndSortThem(double* arr, int size) {
	if (isInputDataCorrect(size)) {
		addElementsToArray(arr, size);

		arrayInAscendingOrder(arr, size);
		cout << "Array in ascending order: ";
		printArray(arr, size);
	}
	else {
		cout << "Error!";
	}
}

void arrayInAscendingOrder(double* arr, int count) {
	double temp = 0;

	for (int k = 0;k < count;k++) {
		for (int p = k + 1;p < count ;p++) {
			if (arr[k] > arr[p]) {
				temp = arr[p];
				arr[p] = arr[k];
				arr[k] = temp;
			}
		}
	}
}

bool isInputDataCorrect(int size) {
	if (size < minArraySize || size>arraySize) {
		return false;
	}
	else {
		return true;
	}
}

void addElementsToArray(double* arr, int size) {
	cout << "Enter the values: ";

	for (int i = 0;i < size;i++) {
		cout << "";
		cin >> arr[i];

		if (i >= size) {
			break;
		}
	}
}

void printArray(double* arr, int count) {
	for (int i = 0;i < count;i++) {
		cout << arr[i] << " ";
	}
}