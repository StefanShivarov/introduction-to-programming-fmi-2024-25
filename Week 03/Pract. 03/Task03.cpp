#include <iostream>

int askUser(const int from, const int to)
{
	int prompt_number = 0;
	int result = 0;

	while (true)
	{
		std::cin >> prompt_number;

		if (prompt_number > from && prompt_number < to)
		{
			result = prompt_number;
			break;
		}
	}

	std::cout << "Program has stopped on: ";
	return result;
}

int main()
{
	int prompt_number_start = 0;
	int prompt_number_end = 0;
	
	std::cout << "Please enter two numbers to create a range: ";
	std::cin >> prompt_number_start >> prompt_number_end;

	std::cout << "Now the cycle will start, please enter the number from your range to stop the cycle: ";
	int asking = askUser(prompt_number_start, prompt_number_end);

	std::cout << asking;

	return 0;
}