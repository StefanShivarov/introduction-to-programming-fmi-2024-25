#include <iostream>

using namespace std;

const size_t  MIN_SIZE = 1, MAX_SIZE = 10;

bool isInputDataValid(int size);

void printError();

void addElementsToArray(char arr[], int N);

long fromKToDecimal(char arr[], int N, int K);

long myPow(int num, int power);

int charToInt(char symbol);

int intToChar(int num);

void fromDecimalToK(char result[], long dec, int K, int& count);

void printArray(char result[], int length);

int main()
{
	int N = 0;
	int K = 0;
	cout << "Enter N and K: ";
	cin >> N >> K;

	if (isInputDataValid(N)) {
		char arr[MAX_SIZE] = {};
		addElementsToArray(arr, N);

		long dec = fromKToDecimal(arr, N, K);
		dec++;

		int count = 0;

		char result[MAX_SIZE] = {};
		fromDecimalToK(result, dec, K, count);
		cout << "Result: ";
		printArray(result, count);
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
	cout << "Enter a number: ";

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

int intToChar(int num) {
	if (num >= 0 && num <= 9) {
		return ((char)(num + '0'));
	}
	else if (num >= 10 && num <= 36) {
		return ((char)(num - 10 + 'A'));
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

void fromDecimalToK(char result[], long dec, int K, int& count) {
	
	for (size_t i = 0; dec > 0; i++) {
		result[i] = intToChar(dec % K);
		dec /= K;

		count++;
	}
}

void printArray(char result[], int length) {

	for (int i = length - 1; i >= 0; i--) {
		cout << result[i];
	}
}