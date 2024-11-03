#include <iostream>

using namespace std;

const size_t arraySize = 50;
const size_t minArraySize = 1;

void addElementsToArray(int*, int);
bool isInputDataCorrect(int);
bool isDifferent(int*, int);
void addElementsToArrayAndCheckIfElementsAreDifferent(int*, int);

int main() {
	int countOfElements = 0;
	int array[arraySize];
	cout << "Enter the number of values in the array: ";
	cin >> countOfElements;

	addElementsToArrayAndCheckIfElementsAreDifferent(array, countOfElements);
 
  return 0;
}

void addElementsToArrayAndCheckIfElementsAreDifferent(int* arr, int size) {
	if (isInputDataCorrect(size)) {
		addElementsToArray(arr, size);

		if (isDifferent(arr, size)) {
			cout << "The sequence consists of distinct elements.";
		}
		else {
			cout << "The sequence does not consist of distinct elements.";
		}
	}
	else {
		cout << "Error!";
	}
}

bool isDifferent(int* arr, int count) {
	for (int k = 1;k < count;k++) {
		for (int p = k-1;p >= 0;p--) {
			if (arr[k] != arr[p]) {
				continue;
			}
			else {
				return false;
				break;
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