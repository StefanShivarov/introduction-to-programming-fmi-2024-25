#include <iostream>

void negativeRows()
{
	const unsigned int MAX_SIZE = 4;
	int numbers[MAX_SIZE][MAX_SIZE] = {};

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
			if (!(numbers[rowIncrement][columnIncrement] % 2))
			{
				numbers[rowIncrement][columnIncrement] *= numbers[rowIncrement][columnIncrement];	
			}
		}
	}

	std::cout << std::endl;

	for (int rowIncrement = 0; rowIncrement < MAX_SIZE; ++rowIncrement)
	{
		for (int columnIncrement = 0; columnIncrement < MAX_SIZE; ++columnIncrement)
		{
			std::cout << numbers[rowIncrement][columnIncrement] << " ";
		}

		std::cout << std::endl;
	}

	return;
}

void main()
{
	negativeRows();
	
	return;
}