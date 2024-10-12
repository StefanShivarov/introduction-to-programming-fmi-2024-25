#include <iostream>

int main()
{
	int year = 0;

	std::cout << "Please enter a year: "; std::cin >> year;

	if ( !(year % 400) ) {
		std::cout << "Leap year";
	} else if ( !(year % 100) ) {
		std::cout << "Not leap";
	} else if ( !(year % 4) ) {
		std::cout << "Leap year";
	}

	return 0;
}