#include <iostream>
using namespace std;

int digitsCount(long num);

void swap(int& a, int& b);

void reverseArr(int arr[], int length);

int* modifiedNumInArray(long num, int n, int m);

int main() {
	long num = 0;
	int n = 0, m = 0;

	cout << "Enter a number: ";
	cin >> num;

	cout << "Enter two positions: ";
	cin >> n >> m;

	int* parr = modifiedNumInArray(num, n, m);

	int length = digitsCount(num);

	for (int i = 0; i < length;i++) {
		cout << parr[i];

		if (i != length - 1) {
			cout << ", ";
		}
	}
	cout << endl;

	delete[] parr;

	return 0;
}

int digitsCount(long num) {
	int count = 0;

	while (num > 0) {
		count++;
		num /= 10;
	}

	return count;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void reverseArr(int arr[], int length) {
	for (int i = 0, j = length - 1; i < j; i++, j--) {
		swap(arr[i], arr[j]);
	}
}

int* modifiedNumInArray(long num, int n, int m) {
	int arrLength = digitsCount(num);

	int* parr = new int[arrLength];

	for (int i = 0; num > 0; i++) {
		parr[i] = num % 10;
		num /= 10;
	}

	reverseArr(parr, arrLength);

	swap(parr[n - 1], parr[m - 1]);

	return parr;
}