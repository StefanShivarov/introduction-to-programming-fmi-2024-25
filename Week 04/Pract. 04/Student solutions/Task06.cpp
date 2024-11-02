#include <iostream>

bool isDecreasing(const int SIZE)
{ 
	const unsigned int MAX_SIZE = 15;
	int numbers[MAX_SIZE] = {};

	for (int increment = 0; increment < SIZE; ++increment)
	{
		std::cin >> numbers[increment];

		if (increment - 1 > 1 && numbers[increment-1] < numbers[increment]) 
		{
			return 0;
		}
	}
}

void main()
{
	int numbersQuantity = 0;

	std::cin >> numbersQuantity;
	bool seriesType = isDecreasing(numbersQuantity);
	
	if (seriesType)
	{
		std::cout << "The series is monotonically decreasing.";
	}
	else
	{
		std::cout << "The series is not monotonically decreasing.";
	}
}