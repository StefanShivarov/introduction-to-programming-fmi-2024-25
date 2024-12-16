#include <iostream>
const size_t MAX_SIZE = 50;
const size_t ERROR_CODE = 0x3F;

size_t numberLength(long num);
long* fillArray(long num, const size_t LENGTH);
void printArray(long* arr, const size_t LENGTH);
void changePosition(long *numbers, const size_t LENGTH, const size_t FIRST_POS, const size_t SECOND_POS);
void changePosition(long *numbers, const size_t FIRST_POS, const size_t SECOND_POS);

int main()
{
	long num = 0;
	size_t n = 0;
	size_t m = 0;

	std::cin >> num >> n >> m;

	n--;
	m--;

	size_t numLength = numberLength(num);
	
	if (m < 0 || n < 0)
	{
		return ERROR_CODE;
	}
	if (m >= numLength || n >= numLength)
	{
		return ERROR_CODE;
	}

	long* result = fillArray(num, numLength);
	changePosition(result, n, m);
	printArray(result, numLength);
	delete[] result;

	return 0;
}

size_t numberLength(long num)
{
	size_t result = 0;
	while (num)
	{
		num /= 10;
		result++;
	}
	return result;
}

void changePosition(long *numbers, const size_t FIRST_POS, const size_t SECOND_POS)
{
	const long TEMP = *(numbers + FIRST_POS);
	*(numbers + FIRST_POS) = *(numbers + SECOND_POS);
	*(numbers + SECOND_POS) = TEMP;
}

long *fillArray(long num, const size_t LENGTH)
{
	long* result = new long[LENGTH];

	for (size_t i = 0; i < LENGTH; i++)
	{
		*(result + LENGTH - 1 - i) = num % 10;
		num /= 10;
	}

	return result;
}

void printArray(long* arr, const size_t LENGTH)
{
	for (size_t i = 0; i < LENGTH; i++)
	{
		if (i == LENGTH - 1)
		{
			std::cout << *(arr + i) << std::endl;
			return;
		}
		std::cout << *(arr + i) << ", ";
	}
}