#include <iostream>

void sumRows()
{
	const unsigned int MAX_SIZE = 4;
	int numbers[MAX_SIZE][MAX_SIZE] = {};
	int sum[MAX_SIZE] = {};

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
			sum[rowIncrement] += numbers[rowIncrement][columnIncrement];
		}
	}

	for (int increment = 0; increment < MAX_SIZE; ++increment)
	{
		std::cout << sum[increment] << " ";
	}

	return;
}

void main()
{
	sumRows();
	
	return;
}