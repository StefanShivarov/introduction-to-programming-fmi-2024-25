#include <iostream>
using namespace std;

const size_t MIN_MATRIX_SIZE = 1, MAX_MATRIX_SIZE = 50;

bool isInputDataValid(size_t size);
void addElementsToMatrix(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols);
int countGroups(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols);

int main()
{
	size_t rowsOfMatrix = MIN_MATRIX_SIZE, colsOfMatrix = MIN_MATRIX_SIZE;
	cout << "Enter the number of rows of the matrix: ";
	cin >> rowsOfMatrix;
	cout << "Enter the number of cols of the matrix: ";
	cin >> colsOfMatrix;

	if (isInputDataValid(rowsOfMatrix) && isInputDataValid(colsOfMatrix)) {
		int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {};

		cout << "Enter the values of the matrix: " << endl;
		addElementsToMatrix(matrix, rowsOfMatrix, colsOfMatrix);

		cout << "Result: ";
		cout << countGroups(matrix, rowsOfMatrix, colsOfMatrix);
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

int countGroups(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols) {
	int count = 0;

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0;j < cols;j++) {
			bool somethingChanged = true;

			if (matrix[i][j] == 0) {
				continue;
			}
			else if (matrix[i][j] == 2) {
				continue;
			}
			else if (matrix[i][j] == 1) {
				count++; 
				matrix[i][j] = 2;

				while (somethingChanged) {
					somethingChanged = false;
					for (size_t i = 0; i < rows; i++) {
						for (size_t j = 0;j < cols;j++) {

							if (matrix[i][j] == 2) {
								if (j + 1 < cols && matrix[i][j + 1] == 1) {
									matrix[i][j + 1] = 2;
									somethingChanged = true;
								}

								if (j - 1 >= 0 && matrix[i][j - 1] == 1) {
									matrix[i][j - 1] = 2;
									somethingChanged = true;
								}

								if (i + 1 < rows && matrix[i + 1][j] == 1) {
									matrix[i + 1][j] = 2;
									somethingChanged = true;
								}
								
								if (i - 1 >= 0 && matrix[i - 1][j] == 1) {
									matrix[i - 1][j] = 2;
									somethingChanged = true;
								}
							}
						}
					}
				}
			}
		}
	}

	return count;
}