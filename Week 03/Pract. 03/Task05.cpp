#include <iostream>
#include <math.h>

bool checkPal (const int CHECK_NUMBER)
{
	int cycle_number = CHECK_NUMBER;
	int reverse_number = 0;
	int increment = 0;

	while (cycle_number)
	{
		cycle_number /= 10;
		++increment;
	}

	cycle_number = CHECK_NUMBER;

	while (cycle_number)
	{
		reverse_number += (cycle_number % 10) * pow(10, increment - 1);

		cycle_number /= 10;
		--increment;
	}

	if (CHECK_NUMBER != reverse_number)
	{
		return false;
	}

	return true;
}

int main()
{
	int prompt_number = 0;
	std::cout << "Please enter a number you want to check for palindrome: ";
	std::cin >> prompt_number;

	bool palindromeCheck = checkPal(prompt_number);
	if (palindromeCheck)
	{
		std::cout << "Your number is a palindrome";
	}
	else
	{
		std::cout << "Your number is not a palindrome";
	}

	return 0;
}