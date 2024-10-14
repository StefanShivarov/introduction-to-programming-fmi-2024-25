#include <iostream>

using namespace std;

int main() {
	int prompt_number = 0;
	int second_number = 0;
	int final_number = 0;

	cout << "Please enter the number which will start a cycle: ";
	cin >> prompt_number;
	while (prompt_number) {
		cin >> second_number;
		
		if (final_number < second_number) {
			final_number = second_number;
		}

		--prompt_number;
	}

	cout << "Out: " << final_number;
}