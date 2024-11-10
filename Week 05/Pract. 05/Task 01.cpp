#include <iostream>
using namespace std;

const size_t MAX_SIZE = 50, MIN_SIZE = 1;

bool isDataValid(size_t length);
void addElements(int arr[], size_t length);
int findLongestLineOfIdenticalNumbers(int arr[], size_t length);

int main() {
	size_t length = 0;
	cout << "Enter the number of values in the array(>=1 and <=50): ";
	cin >> length;

	int array[MAX_SIZE] = {};

	if (isDataValid(length)) {
		cout << "Enter the values of the array: ";
		addElements(array, length);

		cout << findLongestLineOfIdenticalNumbers(array, length);
	}
	else {
		cout << "Incorrect input data!";
	}
 
 	return 0;
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

int findLongestLineOfIdenticalNumbers(int arr[], size_t length) {
	int lineMax = 1;
	int line = 0;

	for (int i = 1;i < length;i++) {
		if (arr[i] == arr[i - 1]) {
			line++;

			if (line >= lineMax) {
				lineMax = line;
			}
		}
		else {
			line = 1;
		}
	}

	return lineMax;
}


