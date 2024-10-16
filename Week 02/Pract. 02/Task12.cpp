#include <iostream>

using namespace std;

int main() {
	int prompt_number = 0;
	int counter = 1;
	int subtractor = 1;
	int floor_subtractor = 1;
	int floor_counter = 1;
	int inside_counter = 1;
	char inside_char = ' ';

	cout << "Please enter number which you want to create a drawing of: ";
	cin >> prompt_number;

	while (counter && counter <= prompt_number) {
		while (floor_counter && floor_counter <= prompt_number+1) {
			if (floor_counter == prompt_number+1) {
				floor_subtractor *= -1;
			}

			if (floor_counter <= counter && floor_counter <= prompt_number) {
				cout << floor_counter << " ";
			} else if (floor_counter > counter && floor_counter > prompt_number) {

			} else {
				cout << "  ";
			}

			while (floor_counter > prompt_number && inside_counter <= prompt_number + 1) {
				if (floor_counter > prompt_number && counter != prompt_number || floor_counter > prompt_number && counter == prompt_number && inside_counter > prompt_number) {
					inside_char = ' ';
				} else if (floor_counter > prompt_number && counter == prompt_number) {
					inside_char = '-';
				}

				cout << inside_char;
				++inside_counter;
			}
			inside_counter = 1;
			floor_counter += floor_subtractor;
		}

		if (counter == prompt_number) {
			subtractor *= -1;
		}
		counter += subtractor;
		cout << endl;
		floor_counter = 1;
		floor_subtractor = 1;
	}
	return 0;
}