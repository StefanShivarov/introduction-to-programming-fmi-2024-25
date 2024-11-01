#include <iostream>

bool isDistinctElem(const int SIZE)
{ 
	bool distinctElem = 1;
	const unsigned int MAX_SIZE = 15;
	int numbers[MAX_SIZE] = {};

	for (int increment = 0; increment < SIZE; ++increment)
	{
		std::cin >> numbers[increment];
	}

	for (int positionIncrement = 0; positionIncrement < SIZE; ++positionIncrement)
	{
		for (int digitIncrement = 0; digitIncrement < SIZE; ++digitIncrement)
		{
			if (positionIncrement != digitIncrement && numbers[positionIncrement] == numbers[digitIncrement])
			{
				distinctElem = 0;
			}
		}
	}

	if (distinctElem)
	{
		std::cout << "Yes, the sequence consists of distinct elements.";
		return distinctElem;
	}
	else
	{
		std::cout << "No, the sequence does not consist of distinct elements.";
		return distinctElem;
	}
}

void main()
{
	int numbersQuantity = 0;

	std::cin >> numbersQuantity;
	bool checkElements = isDistinctElem(numbersQuantity);
	
	return;
}
