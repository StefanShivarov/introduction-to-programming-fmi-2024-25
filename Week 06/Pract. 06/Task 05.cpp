#include <iostream>
using namespace std;

const size_t MIN_MATRIX_SIZE = 1, MAX_MATRIX_SIZE = 50;

bool isInputDataValid(size_t size);
void addElementsToMatrix(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols);
void matrixToArrayInSpiral(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols, int arr[]);

int main()
{
	size_t rows = MIN_MATRIX_SIZE, cols = MIN_MATRIX_SIZE;
	cout << "Enter the number of rows of the matrix: ";
	cin >> rows;
	cout << "Enter the number of cols of the matrix: ";
	cin >> cols;

	if (isInputDataValid(rows) && isInputDataValid(cols)) {
		int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {};

		int arr[MAX_MATRIX_SIZE * MAX_MATRIX_SIZE] = {};
		cout << "Enter the values of the matrix: " << endl;
		addElementsToMatrix(matrix, rows, cols);

		matrixToArrayInSpiral(matrix, rows, cols, arr);

		for (size_t i = 0; i < rows*cols; i++) {
			cout << arr[i] << " ";
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

void matrixToArrayInSpiral(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols, int arr[]) {
	int up = rows, left = cols - 1, down = rows - 1, right = cols - 2;
	int i = 0;

	size_t row = rows - 1, col = cols - 1;

	while (i < rows * cols) {
		for (size_t k = 0;k < up;k++) {
			arr[i] = matrix[row][col];
			i++;

			if (k < up - 1) {
				row--;
			}
		}
		up -= 2;
		col--;

		for (size_t k = 0;k < left;k++) {
			arr[i] = matrix[row][col];
			i++;

			if (k < left - 1) {
				col--;
			}
		}
		left -= 2;
		row++;

		for (size_t k = 0;k < down;k++) {
			arr[i] = matrix[row][col];
			i++;

			if (k < down - 1) {
				row++;
			}
		}
		down -= 2;
		col++;


		for (size_t k = 0;k < right;k++) {
			arr[i] = matrix[row][col];
			i++;

			if (k < right - 1) {
				col++;
			}
		}
		right -= 2;
		row--;
	}
}