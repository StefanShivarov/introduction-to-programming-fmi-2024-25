#include <iostream>
using namespace std;

const int MAX_ARR_LENGTH = 100, lettersInAlphabet = 26;

bool isInputArrayValid(char* arr) {
	while (*arr != '\0') {
		if (*arr < 'a' || *arr>'z') {
			return false;
		}

		arr++;
	}

	return true;
}

int main() {
	char array[MAX_ARR_LENGTH] = {};
	cout << "Enter array: ";
	cin.getline(array, MAX_ARR_LENGTH);

	if (isInputArrayValid(array)) {
		bool arrMask[lettersInAlphabet] = { 0 };
		int ind = 0;


		cout << "Result: ";
		for (int i = 0; array[i] != '\0'; i++) {
			ind = (int)array[i] - (int)('a');

			if (arrMask[ind] == 0) {
				cout << array[i];
				arrMask[ind] = 1;
			}
		}

		cout << endl;
	}
	else {
		cout << "Incorrect array!";
		return -3;
	}

	return 0;
}