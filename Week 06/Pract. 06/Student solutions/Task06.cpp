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

bool isTriangle(size_t (*array)[10], const size_t SIZE)
{
	bool leftMain = 0;
	bool rightMain = 0;
	bool leftAlt = 0;
	bool rightAlt = 0;

	for (size_t i = 0, o = SIZE - 1; i < SIZE; ++i, --o)
	{
		for (size_t j = 0; j < SIZE; ++j)
		{
			if (j < i && !array[i][j])
			{
				leftMain = 1;
			}

			if (j > i && !array[i][j])
			{
				rightMain = 1;
			}

			if (j < o && !array[i][j])
			{
				leftAlt = 1;
			}

			if (j > o && !array[i][j])
			{
				rightAlt = 1;
			}
		}
	}

	if (leftMain && rightMain)
	{
		return !(leftAlt && rightAlt);
	}
	return 1;
}

void main()
{
	const size_t MAX_SIZE = 10;
	size_t numbersData[MAX_SIZE][MAX_SIZE];
	size_t numbersQuantity = 0;
	std::cin >> numbersQuantity;

	fillArray(numbersData, numbersQuantity);
	bool triangle = isTriangle(numbersData, numbersQuantity);
	if(triangle)
	{
		std::cout << "true";
	}
	else
	{
		std::cout << "false";
	}
}