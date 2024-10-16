#include <iostream>

using namespace std;

int main() {
	int prompt_number = 0;
	int counter = 1;
	int subtractor = 1;
	int floor_counter = 0;
	int inside_floor_counter = 0;
	char prompt_sign = 0;

	cout << "Please enter the diamond height and a sign to draw: ";
	cin >> prompt_number >> prompt_sign;

	while (counter && counter <= prompt_number) {
		floor_counter = 0;

		while (floor_counter < counter * 2 - 1) {
			while (inside_floor_counter < prompt_number - counter) {
				cout << " ";

				++inside_floor_counter;
			}

			cout << prompt_sign;

			++floor_counter;
		}

		inside_floor_counter = 0;
		cout << endl;

		if (counter == prompt_number) {
			subtractor *= -1;
		}

		counter += subtractor;
	}
	return 0;
}