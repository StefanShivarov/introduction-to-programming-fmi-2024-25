#include <iostream>

using namespace std;

const size_t arraySize = 50;
const size_t minArraySize = 1;

void addElementsToArray(char*, int);
bool isInputDataCorrect(int);
bool isSymmetric(char*, int);
void addElementsToArrayAndCheckIfArrayIsSymmetric(char*, int);

int main() {
	int countOfElements = 0;
	char array[arraySize];
	cout << "Enter the number of values in the array: ";
	cin >> countOfElements;

	addElementsToArrayAndCheckIfArrayIsSymmetric(array, countOfElements);

	return 0;
}

void addElementsToArrayAndCheckIfArrayIsSymmetric(char* arr, int size) {
	if (isInputDataCorrect(size)) {
		addElementsToArray(arr, size);

		if (isSymmetric(arr, size)) {
			cout << "The array is symmetric.";
		}
		else {
			cout << "The array is not symmetric.";
		}
	}
	else {
		cout << "Error!";
	}
}

bool isSymmetric(char* arr, int count) {
	for (int n = 0, k = count-1;count > 0;n++, k--) {
		if (arr[n] == arr[k]) {
			count -= 2;
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

void addElementsToArray(char* arr, int size) {
	cout << "Enter the values: ";

	for (int i = 0;i < size;i++) {
		cout << "";
		cin >> arr[i];

		if (i >= size) {
			break;
		}
	}
}