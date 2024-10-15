#include <iostream>

using namespace std;

int main() {
	int prompt_number = 0;
	int counter = 0;
	int floor_counter = 0;

	cout << "Please enter the tree height: ";
	cin >> prompt_number;

	counter = prompt_number;

	while (counter) {
		cout << " ";
		--counter;
	}

	cout << " |" << endl;

	while (counter < prompt_number) { 
		while (floor_counter < prompt_number) { 
			if (floor_counter >= prompt_number - counter - 1) { 
				cout << "*";
			} else {
				cout << " ";
			}

			++floor_counter;
		}

		cout << " | "; 
		floor_counter = 0;

		while (floor_counter <= counter) { 
			cout << "*";
			++floor_counter;
		}
		cout << endl; 
		floor_counter = 0;
		++counter;
	}	

	return 0;
}