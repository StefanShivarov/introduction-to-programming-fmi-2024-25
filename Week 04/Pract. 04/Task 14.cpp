#include <iostream>

using namespace std;

const size_t matrixSize = 4;

void addElements(int(*matrix)[matrixSize]);
void modifyingMatrix(int(*matrix)[matrixSize]);
void printMatrix(const int(*matrix)[matrixSize]);

int main() {
	int matrix[matrixSize][matrixSize];
	
	addElements(matrix);
	modifyingMatrix(matrix);
	printMatrix(matrix);
}

void addElements(int (*matrix)[matrixSize]) {
	cout << "Enter the elements of a matrix 4x4: " << endl;

	for (int i = 0; i < matrixSize; i++) {
		for (int k = 0; k < matrixSize; k++) {
			cout << "";
			cin >> matrix[i][k];
		}
	}
}

void modifyingMatrix(int(*matrix)[matrixSize]) {
	for (int i = 0; i < matrixSize; i++) {
		for (int k = 0; k < matrixSize; k++) {
			if (matrix[i][k] % 2 == 0) {
				matrix[i][k] *= matrix[i][k];
			}
		}
	}
}

void printMatrix(const int(*matrix)[matrixSize]) {
	cout << "The modified matrix: " << endl;

	for (int i = 0; i < matrixSize; i++) {
		for (int k = 0; k < matrixSize; k++) {
			cout << matrix[i][k] << " ";
		}
		cout << endl;
	}
}
