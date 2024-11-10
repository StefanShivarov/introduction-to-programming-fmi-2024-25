#include <iostream>
using namespace std;

const size_t MAX_SIZE = 50, MIN_SIZE = 1;

bool isDataValid(size_t length);
void addElements(int arr[], size_t length);
bool isArr2PartOfArr1(int arr1[], size_t length1, int arr2[], size_t length2);

int main() {
	size_t length1 = 0;
	cout << "Enter the number of values in the first array(>=1 and <=50): ";
	cin >> length1;

	size_t length2 = 0;
	cout << "Enter the number of values in the second array(>=1 and <=50): ";
	cin >> length2;

	int array1[MAX_SIZE] = {};
	int array2[MAX_SIZE] = {};

	if (isDataValid(length1) && isDataValid(length2)) {
		cout << "Enter the values of the first array: ";
		addElements(array1, length1);
		cout << "Enter the values of the second array: ";
		addElements(array2, length2);

		if (isArr2PartOfArr1(array1, length1, array2, length2)) {
			cout << "The second array is part of the first array.";
		}
		else {
			cout << "The second array is not part of the first array.";
		}
	}
	else {
		cout << "Incorrect input data!";
	}

 	return 0;
}

bool isArr2PartOfArr1(int arr1[], size_t length1, int arr2[], size_t length2) {
	if (length1 >= length2) {
		int ind = 0;
		for (int i = 0; i < length1;i++) {
			if (arr1[i] == arr2[ind]) {
				if (ind == length2 - 1) {
					return true;
				}

				ind++;
			}
			else {
				i -= ind;
				ind = 0;
			}
		}
		if (ind < length2 - 1) {
			return false;
		}
	}
	else {
		return false;
	}
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




