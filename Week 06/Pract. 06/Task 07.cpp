#include <iostream>
using namespace std;

const size_t MIN_MATRIX_SIZE = 1, MAX_MATRIX_SIZE = 50;

bool isInputDataValid(size_t size);
void addElementsToMatrix(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols);
void swap(int& a, int& b);
void matrixToArray(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols, int arr[]);
void sortArray(int arr[], size_t size);
void arrayToMatrix(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols, int arr[]);
void printMatrix(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols);

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

		int arr[MAX_MATRIX_SIZE * MAX_MATRIX_SIZE] = {};
		matrixToArray(matrix, rowsOfMatrix, colsOfMatrix, arr);

		sortArray(arr, rowsOfMatrix * colsOfMatrix);

		arrayToMatrix(matrix, rowsOfMatrix, colsOfMatrix, arr);

		cout << "Sorted matrix:" << endl;
		printMatrix(matrix, rowsOfMatrix, colsOfMatrix);
	}
	else {
		cout << "Incorrect input data!";
	}

	return 0;
}

void printMatrix(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0;j < cols;j++) {
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}
}

void arrayToMatrix(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols, int arr[]) {
	int ind = 0;

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0;j < cols;j++) {
			matrix[i][j] = arr[ind];
			ind++;
		}
	}
}

void sortArray(int arr[], size_t size) {
	for (int n = 0;n < size;n++) {
		for (int m = 0; m < size - n - 1; m++) {
			if (arr[m] > arr[m + 1]) {
				swap(arr[m], arr[m + 1]);
			}
		}
	}
}

void matrixToArray(int matrix[][MAX_MATRIX_SIZE], size_t rows, size_t cols, int arr[]) {
	size_t ind = 0;
	
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			arr[ind] = matrix[i][j];
			ind++;
		}
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
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