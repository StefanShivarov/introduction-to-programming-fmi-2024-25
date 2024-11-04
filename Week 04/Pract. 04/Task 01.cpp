#include <iostream>

using namespace std;

void swap(int&, int&);

int main() {
	int firstNumber = 0, secondNumber = 0;
	cout << "Enter two numbers: ";
	cin >> firstNumber >> secondNumber;

	swap(firstNumber, secondNumber);

	cout << "Swaped numbers: " << firstNumber << " " << secondNumber;

	return 0;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}