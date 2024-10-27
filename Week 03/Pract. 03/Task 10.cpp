#include <iostream>

using namespace std;

long long sortingNumbersInAscendingOrder(long long);

int main() {
	long long num = 0;
	cout << "Enter a number: ";
	cin >> num;

	cout << "Result: " << sortingNumbersInAscendingOrder(num);

	return 0;
}

long long sortingNumbersInAscendingOrder(long long originalNumber) {
	int workNumber = originalNumber;
	int sortedNumber = 0;
	int counter = 0;
	int oneNumber = 0;

	for (int i = 9;i >= 0;i--) {
		for (int k = 0;workNumber > 0; k++) {
			oneNumber = workNumber % 10;
			if (oneNumber == i) {
				sortedNumber += oneNumber * pow(10, counter);
				counter++;
			}
			workNumber /= 10;
		}
		workNumber = originalNumber;
	}

	return sortedNumber;
}