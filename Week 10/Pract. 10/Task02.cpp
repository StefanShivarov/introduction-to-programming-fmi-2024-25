#include <iostream>

size_t mystrlen(char *symbols);
char *concatenateByCapital(char *first, char *second);
int isCapitalLetter(char symbol);
size_t sizeCount(char *symbols, bool capital = 0);

int main()
{
	const size_t MAX_SIZE = 150;
	char first[MAX_SIZE];
	char second[MAX_SIZE];

	std::cin >> first >> second;

	size_t lengthFirst = mystrlen(first);
	size_t lengthSecond = mystrlen(second);

	if (lengthFirst < 1 || lengthSecond < 1)
	{
		return 1;
	}

	char *result = concatenateByCapital(first, second);
	std::cout << result;

	delete[] result;

	return 0;
}

size_t mystrlen(char *symbols)
{
	size_t i = 0;

	while (*(symbols + i))
	{
		i++;
	}

	return i;
}

char *concatenateByCapital(char *first, char *second)
{
	size_t firstLength = sizeCount(first);
	size_t secondLength = sizeCount(second, 1);
	size_t i = 0;
	size_t j = 0;

	char *newArray = new char[firstLength + secondLength + 1];

	while( *(first + i) )
	{
		int capital = isCapitalLetter(*(first + i));

		if (!capital)
		{
			*(newArray + j) = *(first + i);
			j++;
		}

		i++;
	}

	i = 0;

	while( *(second + i) )
	{
		int capital = isCapitalLetter(*(second + i));
		
		if(capital == 1)
		{
			*(newArray + j) = *(second + i);
			j++;
		}

		i++;
	}

	*(newArray + j) = '\0';
	j++;

	return newArray;
}

size_t sizeCount(char *symbols, bool capital)
{
	size_t i = 0;
	size_t size = 0;

	while (*(symbols + i) )
	{
		int capitalLetter = isCapitalLetter(*(symbols + i));

		if (!capital && !capitalLetter)
		{
			size++;
		}
		else if (capital && capitalLetter == 1)
		{
			size++;
		}
		
		i++;
	}

	return size;
}

int isCapitalLetter(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')
	{
		return 0;
	}
	else if (symbol >= 'A' && symbol <= 'Z')
	{
		return 1;
	}

	return -1;
}