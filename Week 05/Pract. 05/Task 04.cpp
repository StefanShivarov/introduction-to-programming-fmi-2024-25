#include <iostream>
using namespace std;

const size_t MAX_SIZE = 50, MIN_SIZE = 1;

bool isDataValid(size_t length);
void addElements(int arr[], size_t length);
bool isPermutation(int arr1[], size_t length1, int arr2[],
	size_t length2, int arrBool[], size_t lengthBool);

int main() {
	size_t length1 = 0;
	cout << "Enter the number of values in the first array(>=1 and <=50): ";
	cin >> length1;

	size_t length2 = 0;
	cout << "Enter the number of values in the second array(>=1 and <=50): ";
	cin >> length2;

	int array1[MAX_SIZE] = {};
	int array2[MAX_SIZE] = {};
	int arrBool[MAX_SIZE] = {};

	size_t lengthBool = length2;

	if (isDataValid(length1) && isDataValid(length2)) {
		cout << "Enter the values of the first array: ";
		addElements(array1, length1);
		cout << "Enter the values of the second array: ";
		addElements(array2, length2);

		if (isPermutation(array1, length1, array2,
			length2, arrBool, lengthBool)) {
			cout << "The second array is a permutation of the first array.";
		}
		else {
			cout << "The second array is not a permutation of the first array.";
		}
	}
	else {
		cout << "Incorrect input data!";
	}
 
 	return 0;
}

bool isPermutation(int arr1[], size_t length1, int arr2[],
	size_t length2, int arrBool[], size_t lengthBool) {
	const int NOT_ZERO = 1;

	if (length1 == length2) {

		for (int ind1 = 0;ind1 < length1;ind1++) {
			for (int ind2 = 0;ind2 < length2;ind2++) {
				if (arr1[ind1] == arr2[ind2] && arrBool[ind2] == 0) {
					arrBool[ind2] = NOT_ZERO;
				}
			}
		}
	}
	else {
		return false;
	}

	for (int j = 0; j < lengthBool; j++) {
		if (arrBool[j] == 0) {
			return false;
		}
	}
	return true;
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


