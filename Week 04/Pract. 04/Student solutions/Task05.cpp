#include <iostream>

double returnAverage(const int SIZE)
{ 
	double result = 0;
	const unsigned int MAX_SIZE = 15;
	int numbers[MAX_SIZE] = {};

	for (int increment = 0; increment < SIZE; ++increment)
	{
		std::cin >> numbers[increment];
		result += numbers[increment];
	}

	result /= SIZE;

	std::cout << "Average: " << result;

	return result;
}

void main()
{
	int numbersQuantity = 0;

	std::cin >> numbersQuantity;
	double getAverage = returnAverage(numbersQuantity);
	
	return;
}