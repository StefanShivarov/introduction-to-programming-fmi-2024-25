#include <iostream>

int* fillArray(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cin >> array[i];
	}

	return array;
}

double returnAverage(int array[], const int SIZE)
{ 
	double result = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		result += array[i];
	}

	return result /= SIZE;
}

void main()
{
	int numbersQuantity = 0;
	const unsigned int MAX_SIZE = 15;
	int numbersEmpty[MAX_SIZE] = {};

	std::cin >> numbersQuantity;
	int* numbersData = fillArray(numbersEmpty, numbersQuantity);
	double getAverage = returnAverage(numbersData, numbersQuantity);

	std::cout << "Average: " << getAverage;
}