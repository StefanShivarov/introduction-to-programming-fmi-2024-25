#include <iostream>
using namespace std;

const size_t MAX_SQUARE_SIZE = 10, MIN_SQUARE_SIZE = 1;

bool isInputDataValid(size_t squareSize);
void addElementsToSquare(double (*square)[MAX_SQUARE_SIZE], size_t squareSize);
bool checkRowsSum(const double square[][MAX_SQUARE_SIZE], size_t squareSize);
bool checkColsSum(const double square[][MAX_SQUARE_SIZE], size_t squareSize);
bool checkDiagonalsSum(const double square[][MAX_SQUARE_SIZE], size_t squareSize);
double rowsSum(const double square[][MAX_SQUARE_SIZE], size_t squareSize);
double colsSum(const double square[][MAX_SQUARE_SIZE], size_t squareSize);
double diagonalsSum(const double square[][MAX_SQUARE_SIZE], size_t squareSize);

int main() {
	size_t squareSize = 0;
	cout << "Enter the size of the square: ";
	cin >> squareSize;

	double square[MAX_SQUARE_SIZE][MAX_SQUARE_SIZE] = {};

	if (isInputDataValid(squareSize)) {
		cout << "Enter the elements of the square: " << endl;
		addElementsToSquare(square, squareSize);

		if (checkRowsSum(square, squareSize)) {
			double rowSum = rowsSum(square, squareSize);
			if (checkColsSum(square, squareSize)) {
				double colSum = colsSum(square, squareSize);
				if (checkDiagonalsSum(square, squareSize)) {
					double diagonalSum = diagonalsSum(square, squareSize);

					if (rowSum == colSum) {
						if (colSum == diagonalSum) {
							cout << "A magic square.";
						}
						else {
							cout << "Not a magic square.";
						}
					}
					else {
						cout << "Not a magic square.";
					}

				}
				else {
					cout << "Not a magic square.";
				}
			}
			else {
				cout << "Not a magic square.";
			}
		}
		else {
			cout << "Not a magic square.";
		}
	}
	else {
		cout << "Incorrect input data!";
	}

	return 0;
}

void addElementsToSquare(double(*square)[MAX_SQUARE_SIZE], size_t squareSize) {
	for (size_t i = 0; i < squareSize; i++) {
		for (size_t j = 0; j < squareSize; j++) {
			cin >> square[i][j];
		}
	}
}

bool checkRowsSum(const double square[][MAX_SQUARE_SIZE], size_t squareSize) {
	double sumFirstRow = 0;
	double sumRow = 0;

	for (size_t i = 0;i < squareSize;i++) {
		sumFirstRow += square[1][i];
	}

	for (size_t i = 0;i < squareSize;i++) {
		for (size_t j = 0; j < squareSize; j++) {
			sumRow += square[i][j];
		}

		if (sumRow != sumFirstRow) {
			return false;
		}

		sumRow = 0;
	}

	return true;
}

double rowsSum(const double square[][MAX_SQUARE_SIZE], size_t squareSize) {
	double sumFirstRow = 0;

	for (size_t i = 0;i < squareSize;i++) {
		sumFirstRow += square[1][i];
	}

	return sumFirstRow;
}

bool checkColsSum(const double square[][MAX_SQUARE_SIZE], size_t squareSize) {
	double sumFirstCol = 0;
	double sumCol = 0;

	for (size_t i = 0;i < squareSize;i++) {
		sumFirstCol += square[i][1];
	}

	for (size_t i = 0;i < squareSize;i++) {
		for (size_t j = 0; j < squareSize; j++) {
			sumCol += square[j][i];
		}

		if (sumCol != sumFirstCol) {
			return false;
		}

		sumCol = 0;
	}

	return true;
}

double colsSum(const double square[][MAX_SQUARE_SIZE], size_t squareSize) {
	double sumFirstCol = 0;

	for (size_t i = 0;i < squareSize;i++) {
		sumFirstCol += square[i][1];
	}

	return sumFirstCol;
}

bool checkDiagonalsSum(const double square[][MAX_SQUARE_SIZE], size_t squareSize) {
	double sumFirstDiagonal = 0;
	double sumSecondDiagonal = 0;

	for (size_t k = 0;k < squareSize;k++) {
		sumFirstDiagonal += square[k][k];
	}

	for (size_t i = 0, j = squareSize - 1;i < squareSize;i++, j--) {
		sumSecondDiagonal += square[i][j];
	}

	if (sumFirstDiagonal == sumSecondDiagonal) {
		return true;
	}
	else {
		return false;
	}
}

double diagonalsSum(const double square[][MAX_SQUARE_SIZE], size_t squareSize) {
	double sumFirstDiagonal = 0;

	for (size_t k = 0;k < squareSize;k++) {
		sumFirstDiagonal += square[k][k];
	}

	return sumFirstDiagonal;
}

bool isInputDataValid(size_t squareSize) {
	if (squareSize >= MIN_SQUARE_SIZE && squareSize <= MAX_SQUARE_SIZE) {
		return true;
	}
	else {
		return false;
	}
}
