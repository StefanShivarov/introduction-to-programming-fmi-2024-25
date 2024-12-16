#include <iostream>

size_t currentDigitSum(int num);
size_t findHighestDigitSum(int *arr, const size_t LENGTH);
void printNumbersWithSum(size_t position, int *arr, const size_t LENGTH);
void showDigitSums(int *arr, const size_t LENGTH);
int *readArray(const size_t LENGTH);

int main()
{
	size_t length = 0;

	std::cin >> length;

	int *numbers = readArray(length);
	showDigitSums(numbers, length);

	delete[] numbers;

	return 0;
}

void showDigitSums(int *arr, const size_t LENGTH)
{
	const size_t HIGHEST = findHighestDigitSum(arr, LENGTH);

	for (size_t i = 0; i <= HIGHEST; ++i)
	{
		printNumbersWithSum(i, arr, LENGTH);
		std::cout << std::endl;
	}

}

void printNumbersWithSum(size_t position, int *arr, const size_t LENGTH)
{
	bool printed = 0;
	
	for (size_t i = 0; i < LENGTH; ++i)
	{
		size_t digitSum = currentDigitSum(*(arr + i));

		if (position == digitSum)
		{
			std::cout << *(arr + i) << " ";
			printed = 1;
		}
	}

	if (!printed)
	{
		std::cout << "-1";
	}

}

int *readArray(const size_t LENGTH)
{
	int *result = new int[LENGTH];

	for (size_t i = 0; i < LENGTH; ++i)
	{
		std::cin >> *(result + i);
	}

	return result;
}

size_t findHighestDigitSum(int *arr, const size_t LENGTH)
{
	size_t highest = 0;

	for (size_t i = 0; i < LENGTH; ++i)
	{
		size_t digitSum = currentDigitSum(*(arr + i));

		if(highest < digitSum)
		{
			highest = digitSum;
		}
	}

	return highest;
}

size_t currentDigitSum(int num)
{
	int oneDigit = 10;

	if (!(num / oneDigit))
	{
		return num;
	}

	size_t result = 0;

	while (num)
	{
		result += num % 10;
		num /= 10;
	}

	return result;
}