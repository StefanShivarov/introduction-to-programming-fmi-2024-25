#include <iostream>

int main()
{
	int first_number = 0;
	int second_number = 0;
	int third_number = 0;
	int fourth_number = 0;
	int final_sum = 0;

	std::cout << "Please enter four numbers: "; std::cin >> first_number >> second_number >> third_number >> fourth_number;

	if (!(first_number % 2))
	{
		final_sum += first_number;
	}

	if (!(second_number % 2))
	{
		final_sum += second_number;
	}

	if (!(third_number % 2))
	{
		final_sum += third_number;
	}

	if (!(fourth_number % 2))
	{
		final_sum += fourth_number;
	}

	std::cout << final_sum;

	return 0;
}