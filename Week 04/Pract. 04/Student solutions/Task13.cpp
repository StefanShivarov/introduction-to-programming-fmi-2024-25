#include <iostream>

void negativeRows()
{
	const unsigned int MAX_SIZE = 4;
	int numbers[MAX_SIZE][MAX_SIZE] = {};
	int negatives[MAX_SIZE] = {};

	for (int rowIncrement = 0; rowIncrement < MAX_SIZE; ++rowIncrement)
	{
		for (int columnIncrement = 0; columnIncrement < MAX_SIZE; ++columnIncrement)
		{
			std::cin >> numbers[rowIncrement][columnIncrement];
		}
	}

	for (int rowIncrement = 0; rowIncrement < MAX_SIZE; ++rowIncrement)
	{
		for (int columnIncrement = 0; columnIncrement < MAX_SIZE; ++columnIncrement)
		{
			if (numbers[rowIncrement][columnIncrement] < 0)
			{
				++negatives[rowIncrement];	
			}
		}
	}

	for (int increment = 0; increment < MAX_SIZE; ++increment)
	{
		std::cout << negatives[increment] << " ";
	}

	return;
}

void main()
{
	negativeRows();
	
	return;
}