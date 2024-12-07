#include <iostream>
using namespace std;

const int MAX_ARR_LENGTH = 30;

int findLengthOfLongestPrefix(char arr1[], char arr2[], char arr3[]);

void printArr(char* arr, int length);

int main() {
	char arr1[MAX_ARR_LENGTH] = {};
	cout << "Enter first array: ";
	cin.getline(arr1, MAX_ARR_LENGTH);

	char arr2[MAX_ARR_LENGTH] = {};
	cout << "Enter second array: ";
	cin.getline(arr2, MAX_ARR_LENGTH);

	char arr3[MAX_ARR_LENGTH] = {};
	cout << "Enter third array: ";
	cin.getline(arr3, MAX_ARR_LENGTH);

	int lengthOfLongestPrefix = findLengthOfLongestPrefix(arr1, arr2, arr3);

	cout << endl << "The longest prefix: ";
	printArr(arr1, lengthOfLongestPrefix);
	cout << endl;

	return 0;
}

int findLengthOfLongestPrefix(char arr1[], char arr2[], char arr3[]) {
	int i = 0;

	while (arr1[i] != '\0' && arr2[i] != '\0' && arr3[i] != '\0') {
		if (arr1[i] != arr2[i] || arr2[i] != arr3[i]) {
			return i;
		}

		i++;
	}

	return i;
}

void printArr(char* arr, int length) {
	for (int i = 0; i < length;i++) {
		cout << arr[i];
	}
}
