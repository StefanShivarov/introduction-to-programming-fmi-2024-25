#include <iostream>
using namespace std;

const size_t MAX_SIZE = 50, MIN_SIZE = 1;

bool isDataValid(size_t length);
void addElements(int arr[], size_t length);
void modifyingOutputArray(int arr[], size_t length,
	int outputArray[],size_t lengthOfOutputArray);
int absFunction(int num);
void printArray(int arr[], size_t length);

int main() {
	size_t length = 0;
	cout << "Enter the number of values in the array(>=1 and <=50): ";
	cin >> length;

	int array[MAX_SIZE] = {};

	int outputArray[MAX_SIZE] = {};
	size_t lengthOfOutputArray = length - 1;

	if (isDataValid(length)) {
		cout << "Enter the values of the array: ";
		addElements(array, length);

		modifyingOutputArray(array, length, outputArray, lengthOfOutputArray);
		printArray(outputArray, lengthOfOutputArray);
	}
	else {
		cout << "Incorrect input data!";
	}
 
 	return 0;
}

void modifyingOutputArray(int arr[], size_t length,
	int outputArray[], size_t lengthOfOutputArray) {
	int value = 0;

	for (int ind = 0;ind < lengthOfOutputArray; ind++) {
		value = arr[ind] - arr[ind + 1];
		outputArray[ind] = absFunction(value);
	}
}

int absFunction(int num) {
	num = (num >= 0) ? num : -num;
	return num;
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

void printArray(int arr[], size_t length) {
	for (int i = 0;i < length;i++) {
		cout << arr[i] << " ";
	}
}




