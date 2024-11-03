#include <iostream>

using namespace std;

const size_t matrixSize = 4;

void addElements(int(*matrix)[matrixSize]);
void sumOfElementsOnEachRow(const int(*matrix)[matrixSize]);

int main() {
	int matrix[matrixSize][matrixSize];
	
	addElements(matrix);
	sumOfElementsOnEachRow(matrix);
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

void sumOfElementsOnEachRow(const int(*matrix)[matrixSize]) {
	int sumOfRow = 0;
	cout << "The sum of elements on each row is: ";

	for (int i = 0; i < matrixSize; i++) {
		for (int k = 0; k < matrixSize; k++) {
			sumOfRow += matrix[i][k];
		}

		cout << sumOfRow << " ";
		sumOfRow = 0;
	}
}
