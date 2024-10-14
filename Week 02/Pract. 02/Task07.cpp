#include <iostream>

using namespace std;

int main() {
	int prompt_index = 0;
	int fibonacci_previous = 0;
	int fibonacci_current = 1;

	cout << "Please enter Fibonacci index: ";
	cin >> prompt_index;

	if (prompt_index == 1) {
		fibonacci_current = 0;
	}

	while (prompt_index > 3) {
		fibonacci_current += fibonacci_previous;
		fibonacci_previous = fibonacci_current - fibonacci_previous;
		--prompt_index;
	}

	cout << "Out: " << fibonacci_previous + fibonacci_current;
}