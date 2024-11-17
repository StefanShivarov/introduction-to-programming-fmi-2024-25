#include <iostream>
using namespace std;

const size_t MIN_MATRIX_SIZE = 1, MAX_MATRIX_SIZE = 50;

bool isInputDataValid(size_t size);
void matrixInSpiral(int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], size_t size);
void printMatrix(int matrix[][MAX_MATRIX_SIZE], size_t size);

int main()
{
	size_t sizeOfMatrix = MIN_MATRIX_SIZE;
	cout << "Enter the size of the matrix: ";
	cin >> sizeOfMatrix;

	if (isInputDataValid(sizeOfMatrix)) {
		int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {};
		matrixInSpiral(matrix, sizeOfMatrix);

		printMatrix(matrix, sizeOfMatrix);
	}
	else {
		cout << "Incorrect input data!";
	}

	return 0;
}

void matrixInSpiral(int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], size_t size) {
	int right = size, down = size - 1, left = size - 1, up = size - 2;

	size_t i = 1;
	size_t countOfElements = size * size;

	size_t row = 0, col = 0;

	while (i <= countOfElements) {
		for (size_t k = 0; k < right; k++) {
			matrix[row][col] = i;
			i++;

			if (k < right - 1) {
				col++;
			}
		}
		row++;
		right -= 2;

		if (i == countOfElements + 1)
			break;

		for (size_t k = 0; k < down; k++) {
			matrix[row][col] = i;
			i++;

			if (k < down - 1) {
				row++;
			}
		}
		col--;
		down -= 2;

		if (i == countOfElements + 1)
			break;

		for (size_t k = 0; k < left; k++) {
			matrix[row][col] = i;
			i++;

			if (k < left - 1) {
				col--;
			}
		}
		row--;
		left -= 2;

		if (i == countOfElements + 1)
			break;

		for (size_t k = 0; k < up; k++) {
			matrix[row][col] = i;
			i++;

			if (k < up - 1) {
				row--;
			}
		}
		col++;
		up -= 2;

		if (i == countOfElements + 1)
			break;
	}
}

void printMatrix(int matrix[][MAX_MATRIX_SIZE], size_t size) {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
		}	
		cout << endl;
	}
}

bool isInputDataValid(size_t size) {
	return (size >= 1 && size <= 50);
}

