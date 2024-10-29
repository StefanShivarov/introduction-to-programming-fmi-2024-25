#include <iostream>

int calculate(const int a, const int b, char action)
{
	int result = 0;

	if(!b && action == '/')
	{
		result = -32767;
	}
	else if (action == '/')
	{
		result = a / b;
	}

	if (action == '+')
	{
		result = a + b;
	}

	if (action == '-')
	{
		result = a - b;
	}

	if (action == '*')
	{
		result = a * b;
	}

	return result;
}

int main()
{
	int prompt_number_first = 0;
	int prompt_number_second = 0;
	char prompt_operator = ' ';

	std::cout << "Please enter the first number, operator and the second number: ";
	std::cin >> prompt_number_first >> prompt_operator >> prompt_number_second;

	int final_result = calculate(prompt_number_first, prompt_number_second, prompt_operator);

	std::cout << final_result << std::endl;

	return 0;
}