#include <iostream>

int returnDigit(const int CHECK_NUMBER, const int POSITION)
{
	int cycle_number = CHECK_NUMBER;
	int final_digit = 0;
	int increment = 0;

	while (cycle_number)
	{
		cycle_number /= 10;
		++increment;
	}

	cycle_number = CHECK_NUMBER;

	if (POSITION > increment || !POSITION)
	{
		return -1;
	}
	else if (POSITION == increment)
	{
		final_digit = cycle_number % 10;

		return final_digit;
	}
	else {
		while (POSITION < increment)
		{
			cycle_number /= 10;

			--increment;
		}
	}

	final_digit = cycle_number % 10;

	return final_digit;
}

int main()
{
	int prompt_number = 0;
	int prompt_position = 0;

	std::cout << "Please enter a number and the position of the digit you want to print: ";
	std::cin >> prompt_number >> prompt_position;

	int digit = returnDigit(prompt_number, prompt_position);

	std::cout << digit;

	return 0;
}