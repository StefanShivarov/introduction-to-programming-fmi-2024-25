#include <iostream>

const size_t MAX_SIZE = 10;
void fillArray(size_t *array, const size_t SIZE);
void printSubs(size_t *array, const size_t SIZE);
void printCopiedArray(size_t *array, const size_t SIZE);
void printArray(size_t *array, const size_t SIZE);
void printSub(size_t *array, size_t SIZE, size_t numb);

int main()
{
	size_t symbols[MAX_SIZE];
	size_t symbolsLength = 0;

	std::cin >> symbolsLength;
	fillArray(symbols, symbolsLength);
	printSubs(symbols, symbolsLength);

	return 0;
}

void fillArray(size_t *array, const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; ++i)
	{
		std::cin >> array[i];
	}
}

void printSub(size_t *array, size_t SIZE, size_t num)
{
	size_t mask = 1;
	bool printed = 0;
	
	for (int i = 0; i < SIZE; ++i)
	{
		if (num & mask && !printed)
		{
			std::cout << array[i];
			printed = 1;
		}
		else if (num & mask && printed)
		{
			std::cout << " " << array[i];
		}
		mask <<= 1;
	}
}

void printSubs(size_t *array, const size_t SIZE)
{
	size_t subsLimit = 1;
	subsLimit <<= SIZE;
	bool reverted = 0;

	for (int i = 0; i < subsLimit; ++i)
	{
		if(i == 3 && !reverted)
		{
			i = 4;
			reverted++;
		}
		else if (i == 5)
		{
			i = 3;
		}
		else if (i == 4 && reverted)
		{
			i = 5;
		}
		std::cout << "{";
		printSub(array, SIZE, i);
		std::cout << "}" << std::endl;
	}
}

void printArray(char *array, const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; ++i)
	{
		std::cout << array[i];
	}

	std::cout << std::endl;
}