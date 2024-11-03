#include <iostream>

using namespace std;

const size_t arraySize = 50;
const size_t minArraySize = 1;

void addElementsToArray(int*, int);
bool isInputDataCorrect(double);
void averageOfElements(int*, double);
void addElementsToArrayAndFindTheAverage(int*, int);

int main() {
	double countOfElements = 0;
	int array[arraySize];
	cout << "Enter the number of values in the array: ";
	cin >> countOfElements;

	addElementsToArrayAndFindTheAverage(array, countOfElements);

	return 0;
}

void addElementsToArrayAndFindTheAverage(int* arr, int size) {
	if (isInputDataCorrect(size)) {
		addElementsToArray(arr, size);
		averageOfElements(arr, size);
	}
	else{
		cout << "Error!";
	}
}

bool isInputDataCorrect(double size) {
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

void averageOfElements(int* arr, double count) {
	double sum = 0;

	for (int k = 0;k < count;k++) {
		sum += arr[k];
	}

	cout << "The average of all elements is: " << (sum) / count;
}