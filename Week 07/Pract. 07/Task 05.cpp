#include <iostream>

using namespace std;

const size_t  MIN_SIZE = 1, MAX_SIZE = 10;

bool isInputDataValid(int size);

void printError();

void addElementsToArray(char arr[], int N);

long fromKToDecimal(char arr[], int N, int K);

long myPow(int num, int power);

int charToInt(char symbol);

int main()
{
	int N1 = 0, K1 = 0;
	cout << "Enter N and K of first number: ";
	cin >> N1 >> K1;
	cout << "Enter the first number: ";
	char number1[MAX_SIZE] = {};
	addElementsToArray(number1, N1);

	int N2 = 0, K2 = 0;
	cout << "Enter N and K of second number: ";
	cin >> N2 >> K2;
	cout << "Enter the secind number: ";
	char number2[MAX_SIZE] = {};
	addElementsToArray(number2, N2);

	if (isInputDataValid(N1) && isInputDataValid(N2)) {
		int decimal1 = fromKToDecimal(number1, N1, K1);
		int decimal2 = fromKToDecimal(number2, N2, K2);

		if (decimal1 == decimal2) {
			cout << "Equal." << endl;
		}
		else {
			cout << "Not equal." << endl;
		}
	}
	else {
		printError();
	}

	return 0;
}

bool isInputDataValid(int size) {
	return (size >= MIN_SIZE && size <= MAX_SIZE);
}

void printError() {
	cout << "Error!";
}

void addElementsToArray(char arr[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

long myPow(int num, int power) {
	long powNum = 1;

	if (power == 0) {
		return 1;
	}

	for (int i = 1; i <= power; i++) {
		powNum *= num;
	}

	return powNum;
}

int charToInt(char symbol) {
	if (symbol >= '0' && symbol <= '9') {
		return ((int)symbol - (int)'0');
	}
	else if (symbol >= 'A' && symbol <= 'Z') {
		return ((int)symbol - (int)'A' + 10);
	}
	else if (symbol >= 'a' && symbol <= 'z') {
		return ((int)symbol - (int)'a' + 10);
	}
	else {
		return -1;
	}
}

long fromKToDecimal(char arr[], int N, int K) {
	int dec = 0;

	for (int i = N - 1, n = 0; i >= 0; i--, n++) {
		int digit = charToInt(arr[i]);
		dec += digit * myPow(K, n);

		if (digit == (-1)) {
			printError();
			break;
		}
	}

	return dec;
}