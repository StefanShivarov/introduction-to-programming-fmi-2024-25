#include <iostream>

char* fillArray(char array[], const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cin >> array[i];
	}

	return array;
}

bool isSym(char array[], const int SIZE)
{
	for (int startIncrement = 0, endIncrement = SIZE-1; startIncrement < SIZE; ++startIncrement, --endIncrement)
	{
		if (array[startIncrement] != array[endIncrement])
			{
				return 0;
			}
	}

	return 1;
}

void main()
{
	int charsQuantity = 0;
	const unsigned int MAX_SIZE = 15;
	char charsEmpty[MAX_SIZE] = {};

	std::cin >> charsQuantity;
	char* charsData = fillArray(charsEmpty, charsQuantity);

	bool checkSym = isSym(charsData, charsQuantity);
	
	if (checkSym)
	{
		std::cout << "Yes, the array is symmetric";
	}
	else
	{
		std::cout << "No, the array is not symmetric";
	}
}
