#include <iostream>

int* buildArray(int arr[], const int SIZE)
{

	for (int increment = 0; increment < SIZE; ++increment)
	{
		std::cin >> arr[increment];
	}

	return arr;
}

void changeDependency(const int SIZE, bool& dependent, int& ratio, int first_array[], int second_array[])
{
	for (int increment = 0; increment < SIZE; increment++)
	{
		if (!(first_array[increment]) && second_array[increment] || (first_array[increment]) && !(second_array[increment]))
		{
			dependent = 0;
			break;
		}

		if (dependent)
		{
			if ( !(first_array[increment] && second_array[increment]))
			{
				continue;
			}
			if (second_array[increment] / first_array[increment])
			{
				if (!ratio)
				{
					ratio = second_array[increment] / first_array[increment];
				}
				else if (second_array[increment] / first_array[increment] != ratio)
				{
					dependent = 0;
					break;
				}
			}
		}
	}

	return;
}

bool isDependent(const int SIZE)
{
	const unsigned int MAX_SIZE = 15;
	int numbers_first_empty[MAX_SIZE] = {}; 
	int numbers_second_empty[MAX_SIZE] = {}; 
	bool dependent = 1;
	int ratio = 0;

	int *numbers_first = buildArray(numbers_first_empty, SIZE);
	int *numbers_second = buildArray(numbers_second_empty, SIZE);

	changeDependency(SIZE, dependent, ratio, numbers_first, numbers_second);

	if (dependent && !ratio)
	{
		changeDependency(SIZE, dependent, ratio, numbers_first, numbers_second);
	}

	if (dependent)
	{
		std::cout << "Yes, the arrays are linearly dependent";
	}
	else
	{
		std::cout << "No, the arrays are not linearly dependent";
	}

	return dependent;
}

void main()
{
	int numbersQuantity = 0;

	std::cin >> numbersQuantity;
	bool checkElements = isDependent(numbersQuantity);
	
	return;
}
