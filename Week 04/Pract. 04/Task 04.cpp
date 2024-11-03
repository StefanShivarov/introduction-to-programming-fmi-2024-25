#include <iostream>

using namespace std;

void findMinMax(int*, int, int&, int&);
void addElementsToArray(int* arr, int size);

int main() {
	const rsize_t arraySize = 5;
	int minValue = 0, maxValue = 0;
	int array[arraySize];

	addElementsToArray(array, arraySize);
	findMinMax(array, arraySize, minValue, maxValue);

	cout << "The min value is: " << minValue << endl;
	cout << "The max value is: " << maxValue;

	return 0;
}

void addElementsToArray(int* arr, int size) {
	cout << "Enter 5 numbers:";

	for (int i = 0;i < size;i++) {
		cout << "";
		cin >> arr[i];

		if (i >= size) {
			break;
		}
	}
}

void findMinMax(int* arr, int size, int& minValue, int& maxValue) {
	minValue = arr[0];
	maxValue = arr[0];

	for (int k = 0;k < size;k++) {
		if (arr[k] < minValue) {
			minValue = arr[k];
		}
		if (arr[k] > maxValue) {
			maxValue = arr[k];
		}
	}
}