#include <iostream>
using namespace std;

const int MAX_ARR_LENGTH = 15;

bool isLowerCase(char a) {
	return (a >= 'a' && a <= 'z');
}

void addElementsToDestArr(const char* arrSrc, char* arrDest) {
	while (*arrSrc != '\0') {
		if (isLowerCase(*arrSrc)) {
			*arrDest = *arrSrc;

			arrDest++;
		}

		arrSrc++;
	}

	*arrDest = '\0';
}

void printArr(const char* arr) {
	while (*arr != '\0') {
		cout << *arr;
		arr++;
	}
}

int main() {
	char arrSrc[MAX_ARR_LENGTH] = {};
	cout << "Enter array: ";
	cin.getline(arrSrc, MAX_ARR_LENGTH);

	char arrDest[MAX_ARR_LENGTH] = {};

	addElementsToDestArr(arrSrc, arrDest);
	cout << "Only lower case letters: ";
	printArr(arrDest);
	cout << endl;
 
  return 0;
}