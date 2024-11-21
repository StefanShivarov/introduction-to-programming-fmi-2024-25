#include <iostream>

void fillArray(size_t (*array)[10], const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; ++i)
	{
		for (size_t j = 0; j < SIZE; ++j)
		{
			std::cin >> array[i][j];
		}
	}
}

size_t sumDiag(size_t (*array)[10], const size_t MAX_SIZE)
{
	size_t sum = 0;
	for (size_t i = 0; i < MAX_SIZE; ++i)
	{
		size_t endDecrement = MAX_SIZE - i - 1;
		sum += array[i][i];
		if (MAX_SIZE % 2 && i == endDecrement)
		{
			continue;
		}
		sum += array[i][endDecrement];
	}

	return sum;
}

void main()
{
	const size_t MAX_SIZE = 10;
	size_t numbersData[MAX_SIZE][MAX_SIZE];
	size_t numbersQuantity = 0;
	std::cin >> numbersQuantity;

	fillArray(numbersData, numbersQuantity);
	size_t sumDiagonal = sumDiag(numbersData, numbersQuantity);
	std::cout << sumDiagonal;
}