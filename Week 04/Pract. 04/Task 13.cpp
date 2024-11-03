#include <iostream>

using namespace std;

const size_t matrixSize = 4;

void addElements(int(*matrix)[matrixSize]);
void countOfNegativeNumbersOnEachRow(const int(*matrix)[matrixSize]);

int main() {
	int matrix[matrixSize][matrixSize];
	
	addElements(matrix);
	countOfNegativeNumbersOnEachRow(matrix);
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

void countOfNegativeNumbersOnEachRow(const int(*matrix)[matrixSize]) {
	int countOfNegativeNumbers = 0;
	cout << "The count of negative numbers on each row is: ";

	for (int i = 0; i < matrixSize; i++) {
		for (int k = 0; k < matrixSize; k++) {
			if (matrix[i][k] < 0) {
				countOfNegativeNumbers++;
			}
		}

		cout << countOfNegativeNumbers << " ";
		countOfNegativeNumbers = 0;
	}
}
