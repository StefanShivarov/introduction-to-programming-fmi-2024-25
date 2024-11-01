#include <iostream>

bool isSym(const int SIZE)
{ 
	bool symmetric = 1;
	const unsigned int MAX_SIZE = 15;
	char chars[MAX_SIZE] = {};

	for (int increment = 0; increment < SIZE; ++increment)
	{
		std::cin >> chars[increment];
	}

	for (int startIncrement = 0, endIncrement = SIZE-1; startIncrement < SIZE; ++startIncrement, --endIncrement)
	{
		if (chars[startIncrement] != chars[endIncrement])
			{
				symmetric = 0;
			}
	}

	if (symmetric)
	{
		std::cout << "Yes, the array is symmetric";
		return symmetric;
	}
	else
	{
		std::cout << "No, the array is not symmetric";
		return symmetric;
	}
}

void main()
{
	int numbersQuantity = 0;

	std::cin >> numbersQuantity;
	bool checkSym = isSym(numbersQuantity);
	
	return;
}
