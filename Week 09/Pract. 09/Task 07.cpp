#include <iostream>
using namespace std;

const int MAX_ARR_LENGTH = 15;

void printArr(const char* arr, int ind);

char intToChar(int num);

void decToHex(char* arr, int num, int& ind);

int main() {
	int number = 0;
	cout << "Dec: ";
	cin >> number;

	char arrRes[MAX_ARR_LENGTH] = {};
	int ind = 0;

	decToHex(arrRes, number, ind);
	cout << "Hex: ";
	printArr(arrRes, ind);
	cout << endl;

	return 0;
}

void printArr(const char* arr, int ind) {
	for (int i = ind - 1; i >= 0; i--) {
		cout << arr[i];
	}
}

char intToChar(int num) {
	if (num >= 0 && num <= 9) {
		return (char)(num + '0');
	}
	else if (num >= 10 && num <= 15) {
		return (char)(num - 10 +'A');
	}
}

void decToHex(char* arr, int num, int& ind) {
	while (num > 0) {
		arr[ind] = intToChar(num % 16);
		num /= 16;

		ind++;
	} 

	arr[ind] = '\0';
}