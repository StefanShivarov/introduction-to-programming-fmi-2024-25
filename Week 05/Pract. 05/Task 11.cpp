#include <iostream>
using namespace std;

const size_t MAX_SQUARE_SIZE = 10, MIN_SQUARE_SIZE = 1;

bool isInputDataValid(size_t squareSize);
void addElementsToSquare(char(*square)[MAX_SQUARE_SIZE], size_t squareSize);

bool areRowsPalindrome(const char(*square)[MAX_SQUARE_SIZE], size_t squareSize);
void addElementsToRow(const char(*square)[MAX_SQUARE_SIZE],
	char arr[], size_t size, size_t row);

bool areColsPalindrome(const char(*square)[MAX_SQUARE_SIZE], size_t squareSize);
void addElementsToCol(const char(*square)[MAX_SQUARE_SIZE],
	char arr[], size_t size, size_t col);

bool isFirstDiagonalPalindrome(const char(*square)[MAX_SQUARE_SIZE], size_t squareSize);

bool isSecondDiagonalPalindrome(const char(*square)[MAX_SQUARE_SIZE], size_t squareSize);

int main() {
	size_t squareSize = 0;
	cout << "Enter the size of the square: ";
	cin >> squareSize;

	char square[MAX_SQUARE_SIZE][MAX_SQUARE_SIZE] = {};

	if (isInputDataValid(squareSize)) {
		cout << "Enter the elements of the square: " << endl;
		addElementsToSquare(square, squareSize);

		if (areRowsPalindrome(square, squareSize) &&
			areColsPalindrome(square, squareSize)) {
			if (isFirstDiagonalPalindrome(square, squareSize) &&
				isSecondDiagonalPalindrome(square, squareSize)) {
				cout << "A magic palindrome.";
			}
			else {
				cout << "Not a magic palindrome.";
			}
		}
		else {
			cout << "Not a magic palindrome.";
		}
	}
	else {
		cout << "Incorrect input data!";
	}

	return 0;
}

void addElementsToSquare(char (*square)[MAX_SQUARE_SIZE], size_t squareSize) {
	for (size_t i = 0; i < squareSize; i++) {
		for (size_t j = 0; j < squareSize; j++) {
			cin >> square[i][j];
		}
	}
}

bool isSecondDiagonalPalindrome(const char(*square)[MAX_SQUARE_SIZE], size_t squareSize) {
	char arr[MAX_SQUARE_SIZE] = {};

	for (size_t i = 0, k = squareSize - 1;i < squareSize;i++, k--) {
		arr[k] = square[i][k];
	}

	for (size_t j = 0, p = squareSize - 1;j < squareSize;j++, p--) {
		if (arr[j] != square[j][p]) {
			return false;
		}
	}

	return true;
}

bool isFirstDiagonalPalindrome(const char(*square)[MAX_SQUARE_SIZE], size_t squareSize) {
	char arr[MAX_SQUARE_SIZE] = {};

	for (size_t i = 0, k = squareSize - 1;i < squareSize;i++, k--) {
		arr[k] = square[i][i];
	}

	for (size_t j = 0;j < squareSize;j++) {
		if (arr[j] != square[j][j]) {
			return false;
		}
	}

	return true;
}

bool areColsPalindrome(const char(*square)[MAX_SQUARE_SIZE], size_t squareSize) {
	for (size_t col = 0; col < squareSize; col++) {
		char arr[MAX_SQUARE_SIZE] = {};
		addElementsToRow(square, arr, squareSize, col);
		for (size_t row = 0; row < squareSize; row++) {
			if (arr[row] != square[row][col]) {
				return false;
			}
		}
	}
}

void addElementsToCol(const char(*square)[MAX_SQUARE_SIZE],
	char arr[], size_t size, size_t col) {
	for (size_t i = size - 1, k = 0;k < size; i--, k++) {
		arr[i] = square[k][col];
	}
}

bool areRowsPalindrome(const char (*square)[MAX_SQUARE_SIZE], size_t squareSize) {
	for (size_t row = 0; row < squareSize; row++) {
		char arr[MAX_SQUARE_SIZE] = {};
		addElementsToRow(square, arr, squareSize, row);
		for (size_t col = 0; col < squareSize; col++) {
			if (arr[col] != square[row][col]) {
				return false;
			}
		}
	}

	return true;
}

void addElementsToRow(const char (*square)[MAX_SQUARE_SIZE],
	char arr[], size_t size, size_t row) {
	for (size_t i = size - 1, k = 0;k < size; i--, k++) {
		arr[i] = square[row][k];
	}
}

bool isInputDataValid(size_t squareSize) {
	if (squareSize >= MIN_SQUARE_SIZE && squareSize <= MAX_SQUARE_SIZE) {
		return true;
	}
	else {
		return false;
	}
}
