#include <iostream>

using namespace std;

const size_t arraySize = 50;
const size_t minArraySize = 1;

void addElementsToArray(int*, int);
bool isInputDataCorrect(int);
bool isDecreasing(int*, int);
void addElementsToArrayAndCheckIfArrayIsDecreasing(int*, int);

int main() {
	int countOfElements = 0;
	int array[arraySize];
	cout << "Enter the number of values in the array: ";
	cin >> countOfElements;

	addElementsToArrayAndCheckIfArrayIsDecreasing(array, countOfElements);
 
  return 0;
}

void addElementsToArrayAndCheckIfArrayIsDecreasing(int* arr, int size) {
	if (isInputDataCorrect(size)) {
		addElementsToArray(arr, size);

		if (isDecreasing(arr, size)) {
			cout << "The series is monotonically decreasing.";
		}
		else {
			cout << "The series is not monotonically decreasing.";
		}
	}
	else {
		cout << "Error!";
	}
}

bool isDecreasing(int* arr, int count) {
	for (int k = 1;k < count;k++) {
		if (arr[k] < arr[k - 1]) {
			continue;
		}
		else {
			return false;
			break;
		}

		return true;
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

void addElementsToArray(int* arr, int size) {
	cout << "Enter the values: ";

	for (int i = 0;i < size;i++) {
		cout << "";
		cin >> arr[i];

		if (i >= size) {
			break;
		}
	}
}