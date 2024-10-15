#include <iostream>

using namespace std;

int main() {
	int prompt_number = 0;
	int negative_number = 0;
	int counter = 0;

	cout << "Please enter the number which will start a cycle: ";
	while (counter < 3) {
		cin >> prompt_number;
		
		if (prompt_number >= 0) {
			negative_number = 0;
			counter = 0;
		}

		if (prompt_number < 0) {
			if (negative_number > prompt_number) {
				negative_number = prompt_number;
			}

			++counter;
		}
	}

	cout << "Out: " << negative_number;

	return 0;
}