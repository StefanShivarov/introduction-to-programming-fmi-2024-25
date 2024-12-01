#include <iostream>

void printArray(size_t* array, const size_t SIZE);

int main()
{
	const size_t SIZE = 3;
	size_t numbers[SIZE] = {1, 2, 3};

	printArray(numbers, SIZE);
}

void printArray(size_t* array, const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; ++i)
	{
		std::cout << *(array + i) << " ";
	}
}