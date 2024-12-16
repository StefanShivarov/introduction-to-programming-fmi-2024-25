#include <iostream>

size_t mystrlen(char *symbols);
char *concatenate(char *first, char *second);

int main()
{
	const size_t MAX_SIZE = 150;
	char first[MAX_SIZE];
	char second[MAX_SIZE];

	std::cin >> first >> second;

	char *result = concatenate(first, second);

	if (!result)
	{
		return 1;
	}

	std::cout << result;

	delete[] result;

	return 0;
}

size_t mystrlen(char *symbols)
{
	size_t i = 0;

	while (*(symbols + i) )
	{
		i++;
	}

	return i;
}

char *concatenate(char *first, char *second)
{
	size_t firstLength = mystrlen(first);
	size_t secondLength = mystrlen(second);

	if (firstLength < 1 || secondLength < 1)
	{
		return nullptr;
	}

	size_t i = 0;
	size_t j = 0;

	char *newArray = new char[firstLength + secondLength + 1];

	while( *(first + i) )
	{
		*(newArray + i) = *(first + i);

		i++;
	}

	while( *(second + j) )
	{
		*(newArray + i) = *(second + j);

		j++;
		i++;
	}

	*(newArray + i) = '\0';
	i++;

	return newArray;
}