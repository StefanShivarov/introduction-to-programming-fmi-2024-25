#include <iostream>

using namespace std;

int main() {
	int prompt_number = 0;
	int counter = 0;
	int floor_counter = 0;

	cout << "Please enter the number to draw a zipline of numbers: ";
	cin >> prompt_number;

	while (counter < prompt_number) {
		while (floor_counter < prompt_number) {
			if (floor_counter % 2) {
			cout << prompt_number * (floor_counter + 1)-(prompt_number-prompt_number + counter) << " ";
			} else {
				cout << prompt_number * (floor_counter + 1)-(prompt_number-counter-1) << " ";
			}
			++floor_counter;
		}
		floor_counter = 0;
		++counter;
		cout << endl;
	}
	return 0;
}