#include <iostream>

void fillArray(size_t* array, const size_t SIZE);
size_t *highestAddress(size_t *array, const size_t SIZE);

int main()
{
	const size_t MAX_SIZE = 15;
	size_t numbers[MAX_SIZE];
	size_t numbersQuantity = 0;

	std::cin >> numbersQuantity;

	fillArray(numbers, numbersQuantity);

	size_t *address = highestAddress(numbers, numbersQuantity);

	std::cout << address << std::endl;
	// std::cout << *address;
}

size_t *highestAddress(size_t *array, const size_t SIZE)
{
	size_t	highest = 0;
	size_t *address = &highest;

	for (size_t i = 0; i < SIZE; ++i)
	{
		if (*(array + i) > highest)
		{
			highest = *(array + i);
			address = array + i;
		}
	}

	return address;
}

void fillArray(size_t* array, const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; ++i)
	{
			std::cin >> *(array + i);
	}
}