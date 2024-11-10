#include <iostream>
using namespace std;

const size_t MAX_SIZE = 50, MIN_SIZE = 1;

bool isDataValid(size_t length);
void addElements(int arr[], size_t length);
void intersection(int arr1[], int arr2[], size_t length1, size_t length2,
	int arrResult[], size_t &indResult);
bool isIdentical(int arr[], size_t length, int num);
void printArray(int arr[], size_t length);

int main() {
	size_t length1 = 0;
	cout << "Enter the number of values in the first array(>=1 and <=50): ";
	cin >> length1;

	size_t length2 = 0;
	cout << "Enter the number of values in the second array(>=1 and <=50): ";
	cin >> length2;

	if (isDataValid(length1) && isDataValid(length2)) {
		int array1[MAX_SIZE] = {};
		int array2[MAX_SIZE] = {};

		int arrayResult[MAX_SIZE] = {};
		size_t indResult = 0;

		cout << "Enter the values of the first array: ";
		addElements(array1, length1);
		cout << "Enter the values of the second array: ";
		addElements(array2, length2);

		intersection(array1, array2, length1, length2, arrayResult, indResult);

 		cout << "The intersection of the two arrays is: ";
		printArray(arrayResult, indResult);
	}
	else {
		cout << "Incorrect input data!";
	}
 
 	return 0;
}

void intersection(int arr1[], int arr2[], size_t length1, size_t length2,
	int arrResult[], size_t& indResult) {
	for (size_t k = 0;k < length1;k++) {
		for (size_t p = 0;p < length2;p++) {
			if (arr1[k] == arr2[p]) {
				if (isIdentical(arrResult, indResult, arr2[p])) {
					arrResult[indResult] = arr2[p];
					indResult++;
				}
			}
		}
	}
}

void printArray(int arr[], size_t length) {
	for (size_t i = 0;i < length;i++) {
		cout << arr[i] << " ";
	}
}

bool isIdentical(int arr[], size_t length, int num) {
	for (size_t i = 0; i < length; i++) {
		if (arr[i] == num ) {
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
	for (size_t i = 0;i < length;i++) {
		cin >> arr[i];
	}
}


