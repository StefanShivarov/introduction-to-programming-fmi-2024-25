#include <iostream>

using namespace std;

void swap(int* firstNum, int* secondNum) {
	int temp = *firstNum;
	*firstNum = *secondNum;
	*secondNum = temp;
}

int main() {
	int firstNum = 0, secondNum = 0;
	cout << "Enter two numbers: ";
	cin >> firstNum >> secondNum;

	int* ptr1 = &firstNum;
	int* ptr2 = &secondNum;

	swap(*ptr1, *ptr2);
	cout << "Swaped numbers: " << firstNum << " " << secondNum;
}