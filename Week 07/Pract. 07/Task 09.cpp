#include <iostream>

using namespace std;

const size_t MAX_SIZE = 10;

void addElementsToArray(char arr[], int N);

int intToChar(int num);

void fromDecimalToK(char result[], long dec, int K, int& count);

void modifyBinaryNum(char binary[], int pos);

long myPow(int num, int power);

int charToInt(char symbol);

long fromKToDecimal(char arr[], int N, int K);

int main()
{
	int num = 0, pos = 0;
	cout << "Number: ";
	cin >> num;
	cout << "Position: ";
	cin >> pos;

	int K = 2;

	char binary[MAX_SIZE] = {};
	int count = 0;
	fromDecimalToK(binary, num, K, count);

	modifyBinaryNum(binary, pos);

	cout << "Result: " << fromKToDecimal(binary, count, K);

	return 0;
}

void addElementsToArray(char arr[], int N) {
	cout << "Enter a number: ";

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
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

void fromDecimalToK(char result[], long dec, int K, int& count) {
	for (int i = 0; dec > 0; i++) {
		result[i] = intToChar(dec % K);
		dec /= K;

		count++;
	}
}

void modifyBinaryNum(char binary[], int pos) {
	if (binary[pos] == '1') {
		binary[pos] = '0';
	}
	else {
		binary[pos] = '1';
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
}

long fromKToDecimal(char arr[], int N, int K) {
	int dec = 0;

	for (int i = 0; i < N; i++) {
		int digit = charToInt(arr[i]);
		dec += digit * myPow(K, i);
	}

	return dec;
}