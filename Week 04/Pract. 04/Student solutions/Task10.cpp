#include <iostream>

using namespace std;

const size_t arraySize = 50;
const size_t minArraySize = 1;

void addElementsToArray(double*, int);
bool isInputDataCorrect(int);
void arrayInAscendingOrder(double*, int);
bool isThere(double*, int, double);

int main() {
	int countOfElements = 0, x = 0;
	double array[arraySize];
	cout << "Enter the number of values in the array: ";
	cin >> countOfElements;

	addElementsToArray(array, countOfElements);
	cout << "Enter x: ";
	cin >> x;
	arrayInAscendingOrder(array, countOfElements);

	if (isThere(array, countOfElements, x)) {
		cout << "Yes! " << x << " is in the array.";
	}
	else {
		cout << "No!" << x << " is not in the array.";
	}
 
    return 0;
}

bool isThere(double* arr, int count, double x) {
	int beginning = 0, end = count - 1;

	while (beginning <= end)
	{
		int mid = (beginning + end) / 2;
		if (arr[mid] == x)
		{
			return true;
		}
		else if (arr[mid] > x)
		{
			end = mid - 1;
		}
		else
		{
			beginning = mid + 1;
		}
	}

	return false;
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
