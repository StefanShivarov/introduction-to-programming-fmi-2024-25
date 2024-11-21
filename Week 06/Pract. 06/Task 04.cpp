#include <iostream>
using namespace std;

const size_t MIN_MATRIX_SIZE = 1, MAX_MATRIX_SIZE = 50;

bool isInputDataValid(size_t size);
void addElementsToMatrix(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols);
void addElementsToNewMatrix(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols,
	int newMatrix[][MAX_MATRIX_SIZE]);
bool areDiagonalsInAscendingOrder(size_t rows, size_t cols, int newMatrix[][MAX_MATRIX_SIZE]);

int main()
{
	size_t rows = MIN_MATRIX_SIZE, cols = MIN_MATRIX_SIZE;
	cout << "Enter the number of rows of the matrix: ";
	cin >> rows;
	cout << "Enter the number of cols of the matrix: ";
	cin >> cols;

	if (isInputDataValid(rows) && isInputDataValid(cols)) {
		int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {};

		int newMatrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {};

		cout << "Enter the values of the matrix: " << endl;
		addElementsToMatrix(matrix, rows, cols);

		addElementsToNewMatrix(matrix, rows, cols, newMatrix);

		if (areDiagonalsInAscendingOrder(rows, cols, newMatrix)) {
			cout << "diagonals are in ascending order";
		}
		else {
			cout << "diagonals are in non ascending order";
		}
	}
	else {
		cout << "Incorrect input data!";
	}

	return 0;
}

bool isInputDataValid(size_t size) {
	return (size >= 1 && size <= 50);
}

void addElementsToMatrix(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols) {
for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0;j < cols;j++) {
			cin >> matrix[i][j];
		}
	}
}

void addElementsToNewMatrix(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols,
	int newMatrix[][MAX_MATRIX_SIZE]) {
	
	size_t col = 0;
	int endOfForLoop = rows - 1 + cols - 1;

	for (size_t k = 0; k <= endOfForLoop; k++) {

		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0;j < cols;j++) {
				if (i + j == k) {
					newMatrix[k][col] = matrix[i][j];
					col++;
				}
			}
		}
		col = 0;
	}
}

bool areDiagonalsInAscendingOrder(size_t rows, size_t cols, int newMatrix[][MAX_MATRIX_SIZE]) {
	int rowsNewMatrix = rows - 1 + cols - 1 + 1;
	int halfRows = 0;

	if (rowsNewMatrix % 2 == 0) {
		halfRows = rowsNewMatrix / 2;

		for (size_t i = 0; i < halfRows; i++) {
			for (size_t j = 0; j < i; j++) {
				
				if (newMatrix[i][j] < newMatrix[i][j + 1]) {
					return false;
				}
			}
		}

		for (size_t i = halfRows; i < rowsNewMatrix; i++) {
			for (size_t j = 0; j < i - halfRows; j++) {

				if (newMatrix[i][j] < newMatrix[i][j + 1]) {
					return false;
				}
			}
		}
	}
	else {
		halfRows = rowsNewMatrix / 2 + 1;

		for (size_t i = 0; i < halfRows; i++) {
			for (size_t j = 0; j < i; j++) {

				if (newMatrix[i][j] < newMatrix[i][j + 1]) {
					return false;
				}
			}
		}

		for (size_t i = halfRows; i < rowsNewMatrix; i++) {
			for (size_t j = 0; j < i-halfRows; j++) {

				if (newMatrix[i][j] < newMatrix[i][j + 1]) {
					return false;
				}
			}
		}
	}

	return true;
}