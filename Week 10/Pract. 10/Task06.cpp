#include <iostream>
char* returnPrefix(char* first, char* second);
size_t prefixLength(char* first, char* second);

int main()
{
	size_t length = 0;

	std::cin >> length;

	char *firstSymbols = new char[length];
	char *secondSymbols = new char[length];

	std::cin.ignore();
	std::cin.getline(firstSymbols, length);
	std::cin.getline(secondSymbols, length);

	char *result = returnPrefix(firstSymbols, secondSymbols);

	std::cout << result;

	delete[] result;
	delete[] firstSymbols;
	delete[] secondSymbols;
}

char *returnPrefix(char* first, char* second)
{
	size_t length = prefixLength(first, second);

	char *result = new char[length + 1];
	size_t i = 0;
	bool fromBegin = 1;

	while (i < length)
	{
		if (*(first + i) == *(second + i) && fromBegin)
		{
			*(result + i) = *(first + i);
		}
		else if (*(first + i) != *(second + i) && fromBegin)
		{
			fromBegin = 0;
		}

		i++;
	}

	*(result + i) = '\0';

	return result;
}

size_t prefixLength(char* first, char* second)
{
	size_t result = 0;
	size_t i = 0;
	bool fromBegin = 1;

	while (*(first + i))
	{
		if (*(first + i) == *(second + i) && fromBegin)
		{
			result++;
		}
		else if (*(first + i) != *(second + i) && fromBegin)
		{
			fromBegin = 0;
		}

		i++;
	}
	return result;
}