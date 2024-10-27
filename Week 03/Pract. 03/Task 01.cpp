#include <iostream>

using namespace std;

double calculate(const int a, const int b, char action);

int main() {
	char initialChar = '0';
	int firstNum = 0, secondNum = 0;
	char action = initialChar;
	cout << "Enter two numbers: ";
	cin >> firstNum >> secondNum;
	cout << "Enter an action(+, -, *, /): ";
	cin >> action;

	calculate(firstNum, secondNum, action);

	if (secondNum == 0 && action == '/') {
		cout << "Error!";
	}
	else {
		cout << "Result: " << calculate(firstNum, secondNum, action);
	}

	return 0;
}

double calculate(const int a, const int b, char action) {
	switch (action)
	{
	case '+':
		return  a + b;
		break;
	case '-':
		return  a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		if (b != 0) {
			return a / b;
		}
	}
}
