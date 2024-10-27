#include <iostream>
#include <cmath>

using namespace std;

int numberInKPosition(long, int);

int countOfNumbers(long);

int main() {
	long n = 0;
	int k = 0;
	cout << "Enter a number and a position: ";
	cin >> n >> k;

	if (countOfNumbers(n) < k) {
		cout << "Error!";
	}
	else {
		cout << "Result: " << numberInKPosition(n, k);
	}

	return 0;
}

int countOfNumbers(long num) {
	return (int)log10((long)abs(num)) + 1;
}

int numberInKPosition(long n, int k) {
	int numInKposition = abs(n % (int)pow(10, countOfNumbers(n) - k + 1));
	numInKposition /= (int)pow(10, countOfNumbers(n) - k);

	return numInKposition;
}
