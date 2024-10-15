#include <iostream>

using namespace std;

int main() {
	int prompt_number = 0;
	int second_number = 0;
	int sum = 0;

	cout << "Please enter the number which will start a cycle: ";
	cin >> prompt_number;
	while (prompt_number) {
		cin >> second_number;
		sum += second_number;

		--prompt_number;
	}

	cout << "Out: " << sum;

	return 0;
}