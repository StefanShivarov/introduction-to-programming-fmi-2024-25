#include <iostream>

size_t mystrlen(char *symbols);
char *reflect(char *symbols);

int main()
{
	const size_t MAX_SIZE = 150;
	char symbols[MAX_SIZE];

	std::cin >> symbols;

	size_t length = mystrlen(symbols);

	char *result = reflect(symbols);

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

char *reflect(char *symbols)
{
	size_t length = mystrlen(symbols);
	size_t position = length - 1;

	if (length < 1)
	{
		return nullptr;
	}

	size_t i = 0;
	size_t j = 0;

	char *newArray = new char[length + 1];

	while( *(symbols + i) )
	{
		*(newArray + position - i) = *(symbols + i);

		i++;
	}

	*(newArray + length) = '\0';
	i++;

	return newArray;
}