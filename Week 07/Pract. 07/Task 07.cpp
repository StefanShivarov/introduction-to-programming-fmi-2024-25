#include <iostream>

using namespace std;

const size_t MAX_SIZE = 10;

void addElementsToArray(char arr[], int N);

int intToChar(int num);

void fromDecimalToK(char result[], long dec, int K, int& count);

int main()
{
	int num = 0, pos = 0;
	cout << "Number: ";
	cin >> num;
	cout << "Position: ";
	cin >> pos;

	int K = 2;

	char decToBinary[MAX_SIZE] = {};
	int count = 0;
	fromDecimalToK(decToBinary, num, K, count);

	cout << "Bit in " << pos << " position: " << decToBinary[pos];

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

	for (size_t i = 0; dec > 0; i++) {
		result[i] = intToChar(dec % K);
		dec /= K;

		count++;
	}
}