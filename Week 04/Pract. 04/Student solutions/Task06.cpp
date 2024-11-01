#include <iostream>

bool isDecreasing(const int SIZE)
{ 
	bool decreasingSeries = 1;
	const unsigned int MAX_SIZE = 15;
	int numbers[MAX_SIZE] = {};

	for (int increment = 0; increment < SIZE; ++increment)
	{
		std::cin >> numbers[increment];

		if (increment - 1 > 1 && numbers[increment-1] < numbers[increment]) 
		{
			decreasingSeries = 0;
		}
	}

	if (decreasingSeries)
	{
		std::cout << "The series is monotonically decreasing.";
		return decreasingSeries;
	}
	else
	{
		std::cout << "The series is not monotonically decreasing.";
		return decreasingSeries;
	}
}

void main()
{
	int numbersQuantity = 0;

	std::cin >> numbersQuantity;
	bool seriesType = isDecreasing(numbersQuantity);
	
	return;
}