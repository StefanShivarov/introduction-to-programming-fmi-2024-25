#include <iostream>
#include <vector>

using namespace std;

void addElements(vector<vector<int>>& matrix, int rows, int cols);
bool isMultiplicationPossible(int colsOfFirstMatrix, int rowsOfSecondMatrix);
void multiplyAndPrint(const vector<vector<int>> matrixA, int n, int m,
	const vector<vector<int>> matrixB, int p, int q, vector<vector<int>> multipliedMatrix);

int main() {
	cout << "Anxm * Bpxq" << endl;
	int n = 0, m = 0, p = 0, q = 0;

	cout << "Enter n and m: ";
	cin >> n >> m;
	vector<vector<int>> matrixA(n, vector<int>(m));
	addElements(matrixA, n, m);

	cout << "Enter p and q: ";
	cin >> p >> q;
	vector<vector<int>> matrixB(p, vector<int>(q));
	addElements(matrixB, p, q);

	if (isMultiplicationPossible(m, p)) {
		vector<vector<int>> multipliedMatrix(n, vector<int>(q));

		cout << "Multiplied matrix: " << endl;
		multiplyAndPrint(matrixA, n, m, matrixB, p, q, multipliedMatrix);
	}
	else {
		cout << "Multiplication is not possible!";
	}
}

void multiplyAndPrint(const vector<vector<int>> matrixA, int n, int m,
	const vector<vector<int>> matrixB, int p, int q, vector<vector<int>> multipliedMatrix) {

	for (int row = 0;row < n; row++) {
		for (int col = 0; col < q; col++) {

			for (int s = 0;s < m;s++) {
				multipliedMatrix[row][col] += matrixA[row][s] * matrixB[s][col];
			}
			cout << multipliedMatrix[row][col] << " ";
			multipliedMatrix[row][col] = 0;
		}
		cout << endl;
	}
}

void addElements(vector<vector<int>> &matrix, int rows, int cols) {
	cout << "Enter the elements of a matrix " << rows << "x" << cols << ": " << endl;

	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < cols; k++) {
			cin >> matrix[i][k];
		}
	}
}

bool isMultiplicationPossible(int colsOfFirstMatrix, int rowsOfSecondMatrix) {
	if (colsOfFirstMatrix == rowsOfSecondMatrix) {
		return true;
	}
	else {
		return false;
	}
}
