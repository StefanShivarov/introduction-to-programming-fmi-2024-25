#include <iostream>
#include <cmath>

using namespace std;

int countOfNumbers(long);

long long concat(int, int secondNum);

int main() {
	int firstnumber = 0, secondnumber = 0;
	cout << "Enter two numbers: ";
	cin >> firstnumber >> secondnumber;

	cout << concat(firstnumber, secondnumber);

	return 0;
}

int countOfNumbers(long number) {
	return (int)log10((long)number);
}

long long concat(int first, int second) {
	first *= pow(10, countOfNumbers(second) + 1);
	return first + second;
}

