#include <iostream>

int binarySearch(int arr[], int lowPos, int highPos, int x)
{
	while (lowPos <= highPos)
	{
		int midPos = lowPos + (highPos - lowPos) / 2;

		if (arr[midPos] == x)
		{
			return midPos;
		}

		if (arr[midPos] < x)
		{
			lowPos = midPos + 1;
		}
		else
		{
			highPos = midPos - 1;
		}
	}

	return -1;
}

bool isInArray(const int SIZE)
{ 
	const unsigned int MAX_SIZE = 15;
	int numbers[MAX_SIZE] = {};
	int x = 0;

	for (int increment = 0; increment < SIZE; ++increment)
	{
		std::cin >> numbers[increment];
	}

	std::cout << "x: ";
	std::cin >> x;

	int findElement = binarySearch(numbers, 0, SIZE - 1, x);

	if (findElement > -1)
	{
		std::cout << "Yes, " << x << " is in the array.";
		return 1;
	}
	else
	{
		std::cout << "No, " << x << " is not in the array.";
		return 0;
	}
}

void main()
{
	int numbersQuantity = 0;

	std::cin >> numbersQuantity;
	bool checkItem = isInArray(numbersQuantity);
	
	return;
}
