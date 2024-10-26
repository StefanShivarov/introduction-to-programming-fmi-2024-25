#include <iostream>

unsigned long long int sumDigits (const unsigned long long int CHECK_NUMBER)
{
	unsigned long long int final_sum = CHECK_NUMBER;
	unsigned long long int cycle_number = 0;

	while (final_sum > 9)
	{
		while (final_sum)
		{
			cycle_number += final_sum % 10;
			final_sum /= 10;
		}

		final_sum = cycle_number;
		cycle_number = 0;
	}

	return final_sum;
}

void main()
{
	unsigned long long int prompt_number = 0;
	std::cout << "Please enter a number to sum its digits: ";
	std::cin >> prompt_number;

	unsigned long long int summarized = sumDigits(prompt_number);

	std::cout << "\nSum of digits is: " << summarized;

	return;
}