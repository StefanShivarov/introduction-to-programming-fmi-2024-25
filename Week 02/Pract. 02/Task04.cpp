#include <iostream>

using namespace std;

int main() {
	int prompt_number = 0;
	int positive_number = 0;
	int counter = 0;

	cout << "Please enter the number which will start a cycle: ";
	while (counter < 5) {
		cin >> prompt_number;
		
		if (prompt_number >= 0) {
			positive_number += prompt_number;
			++counter;
		}
	}

	cout << "Out: " << positive_number;
}