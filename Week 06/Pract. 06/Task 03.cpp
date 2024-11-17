#include <iostream>
using namespace std;

const size_t MIN_MATRIX_SIZE = 1, MAX_MATRIX_SIZE = 50;

bool isInputDataValid(size_t size);
void addElementsToMatrix(int matrix[][MAX_MATRIX_SIZE], size_t size);
bool isSymmetrical(const int matrix[][MAX_MATRIX_SIZE], size_t size);

int main()
{
	size_t sizeOfMatrix = MIN_MATRIX_SIZE;
	cout << "Enter the size of the matrix: ";
	cin >> sizeOfMatrix;

	if (isInputDataValid(sizeOfMatrix)) {
		int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {};

		cout << "Enter the values of the matrix: " << endl;
		addElementsToMatrix(matrix, sizeOfMatrix);

		if (isSymmetrical(matrix, sizeOfMatrix)) {
			cout << "symmetrical matrix";
		}
		else {
			cout << "not symmetrical matrix";
		}


	}
	else {
		cout << "Incorrect input data!";
	}

	return 0;
}

bool isSymmetrical(const int matrix[][MAX_MATRIX_SIZE], size_t size) {
	for (size_t i = 1;i < size;i++) {
		for (size_t j = 0; j < i; j++) {
			if (matrix[i][j] != matrix[j][i]) {
				return false;
			}
		}
	}

	return true;
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