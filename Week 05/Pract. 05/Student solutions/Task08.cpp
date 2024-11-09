#include <iostream>

void fillArray(int* array, const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cin >> array[i];
	}
}

void section(int* firstArray, const int FIRST_SIZE, int* secondArray, const int SECOND_SIZE, int* resultArray, int& resultSize)
{
	int totalSize = FIRST_SIZE * SECOND_SIZE;
	int counterFirst = 0;
	int counterSecond = 0;

	for (int i = 0; i < totalSize; ++i)
	{
		if (secondArray[counterSecond] == firstArray[counterFirst] )
		{
			resultArray[resultSize] = secondArray[counterSecond];
			++resultSize;
		}
		++counterSecond;
		counterSecond %= SECOND_SIZE;

		if (!(i % FIRST_SIZE) && i)
		{
			++counterFirst;
		}
	}
}

void printArray(int* array, int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << array[i] << " ";
	}
}

void main()
{
	int numbersFirstQuantity = 0;
	int numbersSecondQuantity = 0;
	int numbersResultQuantity = 0;
	const unsigned int MAX_SIZE = 15;
	int numbersFirst[MAX_SIZE];
	int numbersSecond[MAX_SIZE];
	int numbersResult[MAX_SIZE];

	std::cin >> numbersFirstQuantity;
	fillArray(numbersFirst, numbersFirstQuantity);

	std::cin >> numbersSecondQuantity;
	fillArray(numbersSecond, numbersSecondQuantity);
	
	section(numbersFirst, numbersFirstQuantity, numbersSecond, numbersSecondQuantity, numbersResult, numbersResultQuantity);

	printArray(numbersResult, numbersResultQuantity);
}
