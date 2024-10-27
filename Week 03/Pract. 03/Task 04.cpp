#include <iostream>

using namespace std;

void numbersInAscendingOrder(int&, int&, int&);

bool isTriangle(int, int, int);

void printIfTriangle(int);

int main() {
	int rowsOfMatrix = 0;
	const int sidesOfTriangle = 3;

	cout << "Enter the numbers of rows of the matrix: ";
	cin >> rowsOfMatrix;

	printIfTriangle(rowsOfMatrix);

	return 0;
}

void numbersInAscendingOrder(int& a, int& b, int& c) {
	int temp = 0;

	if (a > b) {
		temp = b;
		b = a;
		a = temp;
	}
	if (b > c) {
		temp = c;
		c = b;
		b = temp;
	}
	if (a > b) {
		temp = b;
		b = a;
		a = temp;
	}
}

bool isTriangle(int sideOne, int sideTwo, int sideThree) {
	numbersInAscendingOrder(sideOne, sideTwo, sideThree);

	if (sideOne <= 0) {
		return false;
	}
	else if (sideTwo <= 0) {
		return false;
	}
	else if (sideThree <= 0) {
		return false;
	}
	else if ((sideThree < sideOne + sideTwo) && (sideOne > sideThree - sideTwo)) {
		return true;
	}
	else { 
		return false;
	}
}

void printIfTriangle(int rowsOfMatrix) {
	for (int i = 1; i <= rowsOfMatrix; i++) {
		int sideOne = 0, sideTwo = 0, sideThree = 0;
		cout << "";
		cin >> sideOne >> sideTwo >> sideThree;

		numbersInAscendingOrder(sideOne, sideTwo, sideThree);

		if (isTriangle(sideOne, sideTwo, sideThree)) {
			cout << sideOne << " " << sideTwo << " " << sideThree << endl;
		}
	}
}


