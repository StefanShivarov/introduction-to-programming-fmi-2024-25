#include <iostream>

int* buildArray(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cin >> array[i];
	}

	return array;
}
void changeDependency(const int SIZE, bool& dependent, int& ratio, int firstArray[], int secondArray[])
{
	for (int increment = 0; increment < SIZE; increment++)
	{
		if (!(firstArray[increment]) && secondArray[increment] || (firstArray[increment]) && !(secondArray[increment]))
		{
			dependent = 0;
			break;
		}

		if ( !(firstArray[increment] && secondArray[increment]) && !(secondArray[increment] / firstArray[increment]) )
		{
			continue;
		}

		if (!ratio)
		{
			ratio = secondArray[increment] / firstArray[increment];
		}
		else if (secondArray[increment] / firstArray[increment] != ratio)
		{
			dependent = 0;
			break;
		}
	}

	return;
}

bool isDependent(int arrayFirst[], int arraySecond[], const int SIZE)
{	
	bool dependent = 1;
	int ratio = 0;

	changeDependency(SIZE, dependent, ratio, arrayFirst, arraySecond);

	if (dependent && !ratio)
	{
		changeDependency(SIZE, dependent, ratio, arraySecond, arrayFirst);
	}

	return dependent;
}

void main()
{
	const unsigned int MAX_SIZE = 15;
	int numbersFirstEmpty[MAX_SIZE] = {};
	int numbersSecondEmpty[MAX_SIZE] = {};
	
	int numbersQuantity = 0;

	std::cin >> numbersQuantity;
	int* numbersFirst = buildArray(numbersFirstEmpty, numbersQuantity);
	int* numbersSecond = buildArray(numbersSecondEmpty, numbersQuantity);

	bool checkElements = isDependent(numbersFirst, numbersSecond, numbersQuantity);

	if (checkElements)
	{
		std::cout << "Yes, the arrays are linearly dependent";
	}
	else
	{
		std::cout << "No, the arrays are not linearly dependent";
	}
}
