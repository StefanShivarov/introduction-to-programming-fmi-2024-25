#include <iostream>

void printArray(size_t* array, const size_t SIZE);
void fillArray(size_t* array, const size_t SIZE);
bool isConcatPalindrome(size_t *array, const size_t SIZE);
size_t findPalindrome(size_t *array, const size_t SIZE);
bool checkPalindromes(size_t *array, const size_t SIZE, size_t length);
size_t findPalindrome(size_t *array, const size_t SIZE);

int main()
{
	const size_t MAX_SIZE = 15;
	size_t numbers[MAX_SIZE];
	size_t numbersQuantity = 0;

	std::cin >> numbersQuantity;

	fillArray(numbers, numbersQuantity);

	bool concatted = isConcatPalindrome(numbers, numbersQuantity);
	concatted ? std::cout << "true" : std::cout << "false";
}

bool isConcatPalindrome(size_t *array, const size_t SIZE)
{
	size_t palindromeLength = findPalindrome(array, SIZE);

	if (palindromeLength && palindromeLength < SIZE)
	{
		bool palindromes = checkPalindromes(array, SIZE, palindromeLength);

		return palindromes;
	}

	return 0;
}

bool checkPalindromes(size_t *array, const size_t SIZE, size_t length)
{
	for (size_t i = length, j = SIZE - 1; i < SIZE; ++i, j--)
	{
		if ( *(array + i) != *(array + j))
		{
			return 0;
		}
	}

	return 1;
}


size_t findPalindrome(size_t *array, const size_t SIZE)
{
	size_t longestPalindromeLength = 0;

	for (size_t i = 0; i < SIZE; ++i)
	{
		bool palindrome = 1;
		for (size_t j = 0; j <= i; ++j)
		{

			if ( *(array + i - j) != *(array + j) )
			{
				palindrome = 0;
			}
		}
		if (palindrome)
		{
			longestPalindromeLength = i + 1;
		}
	}

	return longestPalindromeLength;
}

void fillArray(size_t* array, const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; ++i)
	{
			std::cin >> *(array + i);
	}
}