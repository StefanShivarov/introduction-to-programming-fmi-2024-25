#include <iostream>

using namespace std;

const size_t MAX_SIZE = 10;

int intToChar(int num);

void fromDecimalToK(char result[], long dec, int K, int& count);

long myPow(int num, int power);

int charToInt(char symbol);

long fromKToDecimal(char arr[], int N, int K);

int main()
{
	int num = 0, startPos = 0, n = 0;
	cout << "Number: ";
	cin >> num;
	cout << "Position: ";
	cin >> startPos;
	cout << "Number of digits: ";
	cin >> n;

	int K = 2;

	char binary[MAX_SIZE] = {};
	int count = 0;
	fromDecimalToK(binary, num, K, count);

	char result[MAX_SIZE] = {};
	int resLength = count - (startPos + 1);

	for (size_t i = 0; i < resLength; i++) {
		result[i] = binary[count - 1 - i];
	}

	cout << "Result: " << fromKToDecimal(result, resLength, K);

	return 0;
}

int intToChar(int num) {
	if (num >= 0 && num <= 9) {
		return ((char)(num + '0'));
	}
	else if (num >= 10 && num <= 36) {
		return ((char)(num - 10 + 'A'));
	}
	else {
		return -1;
	}
}

void fromDecimalToK(char result[], long dec, int K, int& count) {
	for (size_t i = 0; dec > 0; i++) {
		result[i] = intToChar(dec % K);
		dec /= K;

		count++;
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

	for (int i = N - 1, n = 0; i >= 0; i--, n++) {
		int digit = charToInt(arr[i]);
		dec += digit * myPow(K, n);
	}

	return dec;
}