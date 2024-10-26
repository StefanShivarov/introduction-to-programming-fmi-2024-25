#include <iostream>

using namespace std;

int main() {

	int prompt_number = 0;

	cout << "Please enter the number: ";
	cin >> prompt_number;

	for (int i = prompt_number; i > -1;  i--) {
		if (prompt_number - pow(2,i) >= 0) {
			prompt_number -= pow(2, i);
			cout << "2^" << i << " ";

			if (prompt_number > 0 && i > 0) {
				cout << "+ ";
			}
		}
	}

	return 0;
}