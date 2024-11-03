#include <iostream>

using namespace std;

const size_t arraySize = 50;
const size_t minArraySize = 1;

void addElementsToArray(int*, int);
bool isInputDataCorrect(int);
bool isLinearlyDependent(int*, int*, int, int);
void addElementsToArrayAndCheckIflinearlyDependent(int*, int*, int, int);

int main() {
	int countOfElements1 = 0, countOfElements2 = 0;
	int array1[arraySize], array2[arraySize];
	cout << "Enter the number of values in the first array: ";
	cin >> countOfElements1;

	cout << "Enter the number of values in the second array: ";
	cin >> countOfElements2;

	addElementsToArrayAndCheckIflinearlyDependent(array1, array2, countOfElements1, countOfElements2);
 
    return 0;
}

void addElementsToArrayAndCheckIflinearlyDependent(int* arr1, int* arr2, int count1, int count2) {
	if (isInputDataCorrect(count1) && isInputDataCorrect(count2)) {
		addElementsToArray(arr1, count1);
		addElementsToArray(arr2, count2);

		if (isLinearlyDependent(arr1, arr2, count1, count2)) {
			cout << "The arrays are linearly dependent.";
		}
		else {
			cout << "The arrays are not linearly dependent.";
		}
	}
	else {
		cout << "Error!";
	}
}

bool isLinearlyDependent(int* arr1, int* arr2, int count1, int count2) {
	if (count1 != count2) {
		return false;
	}
	else {
		if (arr1[0] > arr2[0]) {
			int quotient = arr1[0] / arr2[0];

			for (int i = 1;i < count1;i++) {
				if (arr1[i] / arr2[i] == quotient) {
					continue;
				}
				else {
					return false;
					break;
				}

				return true;
			}
		}
		else {
			int quotient = arr2[0] / arr1[0];

			for (int i = 1;i < count1;i++) {
				if (arr2[i] / arr1[i] == quotient) {
					continue;
				}
				else {
					return false;
					break;
				}

				return true;
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
