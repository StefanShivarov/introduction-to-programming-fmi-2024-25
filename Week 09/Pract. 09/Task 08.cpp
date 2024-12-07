#include <iostream>
using namespace std;

const int MAX_ARR_LENGTH = 100;

void printArr(const char* arr);

int myStrLen(char* arr);

void modifyArray(char* arr, char* subArr);

bool containsSubArr(char* arr, char* subArr, int i);

char toLower(char a);

void modifyArray(char* arr, char* subArr);

int main() {
	char text[MAX_ARR_LENGTH] = {};
	cout << "Enter text: ";
	cin.getline(text, MAX_ARR_LENGTH);

	char subText[MAX_ARR_LENGTH] = {};
	cout << "Enter subtext: ";
	cin.getline(subText, MAX_ARR_LENGTH);

	modifyArray(text, subText);

	printArr(text);

	return 0;
}

int myStrLen(char* arr) {
	int length = 0;

	while (*arr != '\0') {
		length++;

		arr++;
	}

	return length;
}

void modifyArray(char* arr, char* subArr) {
	int subLen = myStrLen(subArr);

	for (int i = 0; arr[i] != '\0'; i++) {

		if (containsSubArr(arr, subArr, i)) {
			for (int k = i, p = 0; subArr[p] != '\0'; k++, p++) {
				arr[k] = '*';
			}

			i += subLen;
		}

	}
}

bool containsSubArr(char* arr, char* subArr, int i) {

	for (int j = 0; subArr[j] != '\0'; j++) {
		if (toLower(arr[i]) != toLower(subArr[j])) {
			return false;
		}

		i++;
	}

	return true;
}

char toLower(char a) {
	if (a >= 'A' && a <= 'Z') {
		return (char)(a + ('a'-'A'));
	}
	else {
		return a;
	}
}

void printArr(const char* arr) {
	cout << "Result: ";

	while (*arr != '\0') {
		cout << *arr;
		arr++;
	}

	cout << endl;
}