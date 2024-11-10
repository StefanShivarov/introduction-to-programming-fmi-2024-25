#include <iostream>

using namespace std;

const size_t MAX_SIZE = 10, MIN_SIZE = 1, NUMBER_OF_TRIANGLE_SIDES = 3, MAX_SIZE_OF_ARRAY = 30;

bool isInputDataValid(size_t);
void addElementsToMatrix(int(*matrix)[NUMBER_OF_TRIANGLE_SIDES], int rows);
int findNumOfTrianglesAndAddSidesToArray(const int(*matrix)[NUMBER_OF_TRIANGLE_SIDES], int rows,
	int(*triangles));
void addElementsToArray(int a, int b, int c, size_t ind, int (*triangles));
void printTriangles(const int *triangles, int countOftriangles);

int main() {
	int rowsOfMatrix = 0;
	cout << "Enter the number of triangle sides combination you want to check (>1 and <10): ";
	cin >> rowsOfMatrix;

	int matrix[MAX_SIZE][NUMBER_OF_TRIANGLE_SIDES] = {};

	if (isInputDataValid(rowsOfMatrix)) {
		cout << "Enter the combinations of triangle sides: ";
		addElementsToMatrix(matrix, rowsOfMatrix);

		int triangles[MAX_SIZE_OF_ARRAY] = {};
		int trianglesCount = findNumOfTrianglesAndAddSidesToArray(matrix, rowsOfMatrix, triangles);

		cout << endl << "Triangles: " << endl;
		printTriangles(triangles, trianglesCount);
	}
	else {
		cout << "Incorrect input data!";
	}
 
 	return 0;
}

void printTriangles(const int *triangles, int countOftriangles) {
	size_t ind = 0;

	for (size_t i = 0; i < countOftriangles * 3; i++) {
		cout << triangles[i] << " ";
		ind++;

		if (ind == 3) {
			cout << endl;
			ind = 0;
		}
	}
}

void addElementsToArray(int a, int b, int c, size_t ind, int(*triangles)) {
	for (size_t j = ind;j < ind + NUMBER_OF_TRIANGLE_SIDES;j++) {
		if (j == ind) {
			triangles[j] = a;
		}
		else if (j == ind + 1) {
			triangles[j] = b;
		}
		else if (j == ind + 2) {
			triangles[j] = c;
		}
	}
}

int findNumOfTrianglesAndAddSidesToArray(const int(*matrix)[NUMBER_OF_TRIANGLE_SIDES], int rows,
	int(*triangles)) {

	int trianglesCount = 0;
	size_t ind = 0;

	for (size_t k = 0;k < rows;k++) {
		int sideOne = matrix[k][0], sideTwo = matrix[k][1], sideThree = matrix[k][2];

		if (sideOne > 0 && sideTwo > 0 && sideThree > 0) {

			if (sideOne < (sideTwo + sideThree)) {
				if (sideTwo < (sideOne + sideThree)) {
					if (sideThree < (sideOne + sideTwo)) {
						addElementsToArray(sideOne, sideTwo, sideThree, ind, triangles);
						ind += 3;
						trianglesCount++;
					}
				}
			}
		}
	}

	return trianglesCount;
}

void addElementsToMatrix(int (* matrix)[NUMBER_OF_TRIANGLE_SIDES], int rows) {
	for (int k = 0;k < rows;k++) {
		for (int i = 0; i < NUMBER_OF_TRIANGLE_SIDES;i++) {
			cin >> matrix[k][i];
		}
	}
}

bool isInputDataValid(size_t size) {
	if (size >= MIN_SIZE && size <= MAX_SIZE) {
		return true;
	}
	else {
		return false;
	}
}
