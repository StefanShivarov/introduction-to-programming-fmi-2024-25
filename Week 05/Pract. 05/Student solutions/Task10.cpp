#include <iostream>

void fillArray(int (*array)[10], const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			std::cin >> array[i][j];
		}
	}
}

bool areRowsMagic(int (*array)[10], const int MAX_SIZE, bool rows = 1)
{
	int previousResult = 0;
	int result = 0;

	for (int i = 0; i < MAX_SIZE; ++i)
	{
		for (int j = 0; j < MAX_SIZE; ++j)
		{
			if (rows)
			{
				result += array[i][j];
			}
			else
			{
				result += array[j][i];
			}
		}

		if (i && result != previousResult)
		{
			return 0;
		}

		previousResult = result;
		result = 0;
	}

	return 1;
}

bool areDiagMagic(int (*array)[10], const int MAX_SIZE)
{
	int mainResult = 0;
	int result = 0;

	for (int i = 0, j = MAX_SIZE - 1; i < MAX_SIZE; ++i, j--)
	{
		mainResult += array[i][i];
		result += array[j][i];
	}


	if ( result != mainResult)
	{
		return 0;
	}

	return 1;
}


bool isMagic(int (*array)[10], const int MAX_SIZE)
{
	bool rows = areRowsMagic(array, MAX_SIZE);
	bool cols = areRowsMagic(array, MAX_SIZE, 0);
	bool diag = areDiagMagic(array, MAX_SIZE);

if (rows && cols && diag)
{
	return 1;
}

return 0;

}

void main()
{
	const unsigned int MAX_SIZE = 10;
	int numbersData[MAX_SIZE][MAX_SIZE];
	int numbersQuantity = 0;
	std::cin >> numbersQuantity;

	fillArray(numbersData, numbersQuantity);
	bool magic = isMagic(numbersData, numbersQuantity);

	if (magic)
	{
		std::cout << "magic";
	}
	else
	{
		std::cout << "not magic";
	}

}