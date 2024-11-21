#include <iostream>
using namespace std;

const size_t MIN_MATRIX_SIZE = 1, MAX_MATRIX_SIZE = 50;

bool isInputDataValid(size_t size);
void addElementsToMatrix(double matrix[][MAX_MATRIX_SIZE], size_t size);
double sumOfDiagonals(const double matrix[][MAX_MATRIX_SIZE], size_t size);

int main()
{
	size_t sizeOfMatrix = MIN_MATRIX_SIZE;
	cout << "Enter the size of the matrix: ";
	cin >> sizeOfMatrix;

	if (isInputDataValid(sizeOfMatrix)) {
		double matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {};

		cout << "Enter the values of the matrix: " << endl;
		addElementsToMatrix(matrix, sizeOfMatrix);

		cout << "The sum of the diagonals is " << sumOfDiagonals(matrix, sizeOfMatrix) << endl;
	}
	else {
		cout << "Incorrect input data!";
	}


	return 0;
}

bool isInputDataValid(size_t size) {
	return (size >= 1 && size <= 50);
}

void addElementsToMatrix(double matrix[][MAX_MATRIX_SIZE], size_t size) {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0;j < size;j++) {
			cin >> matrix[i][j];
		}
	}
}

double sumOfDiagonals(const double matrix[][MAX_MATRIX_SIZE], size_t size) {
	double sumFirstDiagonal = 0;
	double sumSecondDiagonal = 0;

	for (size_t i = 0; i < size;i++) {
		sumFirstDiagonal += matrix[i][i];

		sumSecondDiagonal += matrix[i][size - i - 1];
	}

	if (size % 2 == 0) {
		return (sumFirstDiagonal + sumSecondDiagonal);
	}
	else {
		return (sumFirstDiagonal + sumSecondDiagonal - matrix[size / 2][size / 2]);
	}
}