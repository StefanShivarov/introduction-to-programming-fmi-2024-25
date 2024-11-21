#include <iostream>
using namespace std;

const size_t MIN_MATRIX_SIZE = 1, MAX_MATRIX_SIZE = 50;

bool isInputDataValid(size_t size);
void addElementsToMatrix(int matrix[][MAX_MATRIX_SIZE], size_t size);
bool isTriangle(const int matrix[][MAX_MATRIX_SIZE], size_t size);
int elementsUnderBelowDiagonal(size_t size);

int main()
{
	size_t sizeOfMatrix = MIN_MATRIX_SIZE;
	cout << "Enter the size of the matrix: ";
	cin >> sizeOfMatrix;

	if (isInputDataValid(sizeOfMatrix)) {
		int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {};

		cout << "Enter the values of the matrix: " << endl;
		addElementsToMatrix(matrix, sizeOfMatrix);

		if (isTriangle(matrix, sizeOfMatrix)) {
			cout << "triangle matrix";
		}
		else {
			cout << "not triangle matrix";
		}
	}
	else {
		cout << "Incorrect input data!";
	}

	return 0;
}

int elementsUnderBelowDiagonal(size_t size) {
	int countOfElemets = 0;

	for (int i = 1; i < size; i++) {
		countOfElemets += i;
	}

	return countOfElemets;
}

bool isTriangle(const int matrix[][MAX_MATRIX_SIZE], size_t size) {
	int countOfElemetsBelowDiagonal = elementsUnderBelowDiagonal(size);
	int countOfElemetsAboveDiagonal = elementsUnderBelowDiagonal(size);

	int zerosBelow = 0;
	int zerosAbove = 0;

	for (size_t i = 1;i < size;i++) {
		for (size_t j = 0; j < i; j++) {
			if (matrix[i][j] == 0) {
				zerosBelow++;
			}
			if (matrix[j][i] == 0) {
				zerosAbove++;
			}
		}
	}

	if (zerosBelow == countOfElemetsBelowDiagonal || zerosAbove == countOfElemetsAboveDiagonal) {
		return true;
	}
	else {
		return false;
	}
}

bool isInputDataValid(size_t size) {
	return (size >= 1 && size <= 50);
}

void addElementsToMatrix(int matrix[][MAX_MATRIX_SIZE], size_t size) {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0;j < size;j++) {
			cin >> matrix[i][j];
		}
	}
}