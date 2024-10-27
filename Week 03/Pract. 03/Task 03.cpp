#include <iostream>

using namespace std;

double askUser(const int, const int);

void swapBeginningAndEndOfTheInterval(double&, double&);

int main() {
	double intervalBeginning = 0, intervalEnd = 0;
	cout << "Enter the beginning and the end of the interval: ";
	cin >> intervalBeginning >> intervalEnd;

	swapBeginningAndEndOfTheInterval(intervalBeginning, intervalEnd);

	cout << "Result:" << askUser(intervalBeginning, intervalEnd);

	return 0;
}

void swapBeginningAndEndOfTheInterval(double& intervalBeginning, double& intervalEnd) {
	if (intervalBeginning > intervalEnd) {
		intervalEnd += intervalBeginning;
		intervalBeginning = intervalEnd - intervalBeginning;
		intervalEnd -= intervalBeginning;
	}
}

double askUser(const int from, const int to) {
	bool isOutOfInterval = true;
	double number = 0;

	for (int i = 0; isOutOfInterval; i++)
	{
		cout << "Enter a number: ";
		cin >> number;

		if (number > from && number < to)
		{
			isOutOfInterval = false;
			return number;
			break;
		}
	}
}
