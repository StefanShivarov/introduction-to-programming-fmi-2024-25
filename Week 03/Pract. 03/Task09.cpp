#include <iostream>
#include <math.h>

int concat(const int first, const int second)
{
	int cycle_number = second;
	int final_number = 0;
	int increment = 0;

	while (cycle_number)
	{
		cycle_number /= 10;
		++increment;
	}

	final_number = first * pow(10, increment) + second;
	return final_number;
}

int main()
{
	int prompt_first_number = 0;
	int prompt_second_number = 0;

	std::cout << "Please enter two numbers you wish to concatenate: ";
	std::cin >> prompt_first_number >> prompt_second_number;

	int result = concat(prompt_first_number, prompt_second_number);

	std::cout << result;

	return 0;
}