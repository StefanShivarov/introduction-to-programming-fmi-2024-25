#include <iostream>
using namespace std;

const int MAX_ARR_LENGTH = 30;

bool isCountXEven(int count);

void modifyArray(char* arr, char x, char a, char b);

void printArr(const char* arr);

int main() {
	char arr[MAX_ARR_LENGTH] = {};
	cout << "Enter array: ";
	cin.getline(arr, MAX_ARR_LENGTH);

	char x = 0, a = 0, b = 0;
	cout << "Enter x, a and b: ";
	cin >> x >> a >> b;

	modifyArray(arr, x, a, b);
	printArr(arr);

	return 0;
}

bool isCountXEven(int count) {
	return (count % 2 == 0);
}

void modifyArray(char* arr, char x, char a, char b) {
	int countX = 0;

	while (*arr != '\0') {
		if (*arr == x) {
			if (isCountXEven(countX)) {
				*arr = a;
			}
			else {
				*arr = b;
			}

			countX++;
		}

		arr++;
	}
}

void printArr(const char* arr) {
	while (*arr != '\0') {
		cout << *arr;
		arr++;
	}
}