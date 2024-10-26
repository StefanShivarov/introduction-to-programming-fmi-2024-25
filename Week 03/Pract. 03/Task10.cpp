#include <iostream>
#include <math.h>

unsigned int sortDigits(const unsigned int NUMBER)
{
	unsigned int highest_digit = 0;
	unsigned int cycled_digit = 0;
	unsigned int cycle_number = NUMBER;
	unsigned int digit_count = 0;
	unsigned int increment = 0;
	unsigned int number_length = 0;
	unsigned int sorted_number_increment = 0;
	unsigned int sorted_number = 0;

	if (NUMBER > 0)
	{
		highest_digit = NUMBER % 10;
	}
	else
	{
		std::cout << "Incorrect value entered.";
		return -1;
	}

	while (cycle_number)
	{		
		++number_length;
		cycle_number /= 10;
		cycled_digit = cycle_number % 10;
		if (highest_digit < cycled_digit)
		{
			highest_digit = cycled_digit;
		}
	}

	cycle_number = NUMBER;

	while (highest_digit)
	{
		while (increment < number_length)
		{
		cycled_digit = cycle_number % 10;
		cycle_number /= 10;

			if (cycled_digit == highest_digit)
			{
				++digit_count;
			}

			++increment;
		}

		while (digit_count)
		{
			sorted_number += highest_digit * pow(10, sorted_number_increment);
			++sorted_number_increment;
			--digit_count;
		}

		cycle_number = NUMBER;
		increment = 0;
		--highest_digit;
	}

	return sorted_number;
}

int main()
{
	unsigned int prompt_number = 0;

	std::cout << "Enter a number and you will get a sorted digits of it: ";
	std::cin >> prompt_number;

	unsigned int result = sortDigits(prompt_number);

	std::cout << result;

	return 0;
}