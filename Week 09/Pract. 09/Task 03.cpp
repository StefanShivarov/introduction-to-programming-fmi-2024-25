#include <iostream>
using namespace std;

const int MAX_ARR_LENGTH = 15;

bool isIntervalValid(int beg, int end) {
	return (beg < end);
}

void addElementsToDestArr(const char* arrSrc, char* arrDest, int beg, int end) {
	int ind = 0;

	for (int i = beg; arrSrc[i] != '\0' && i <= end; i++) {
		arrDest[ind] = arrSrc[i];

		ind++;
	}

	 arrDest[ind] = '\0';
}

void printArr(const char* arr) {
	while (*arr != '\0') {
		cout << *arr;
		arr++;
	}
}

int main() {
	char arr[MAX_ARR_LENGTH] = {};
	cout << "Enter array: ";
	cin.getline(arr, MAX_ARR_LENGTH);

	int beg = 0, end = 0;
	cout << "Enter beg and end: ";
	cin >> beg >> end;

	char subArr[MAX_ARR_LENGTH] = {};

	if (!isIntervalValid(beg, end)) {
		cout << "Invalid interval!" << endl;
		return -3;
	}

	addElementsToDestArr(arr, subArr, beg, end);

	printArr(subArr);
	cout << endl;

	return 0;
}