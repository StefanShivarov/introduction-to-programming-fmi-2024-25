#include <iostream>

const size_t MAX_SIZE = 30;

size_t myStrlen(char *symbols);
void changeStr(char *source, char *dest);
char returnSymbol(char *symbols, size_t startPos, size_t symbolStep);
size_t findStrEnd(char *source);
void substring(char *source, char *dest, size_t beg, size_t end);

int main()
{
	char words[MAX_SIZE];
	char result[MAX_SIZE];

	std::cin.getline(words, MAX_SIZE);

	changeStr(words, result);

	std::cout << result;
}

size_t myStrlen(char *symbols)
{
	size_t i = 0;

	while(*(symbols + i))
	{
		i++;
	}

	return i;
}

size_t findStrEnd(char *source)
{
	size_t position = 0;
	size_t i = 0;

	while (*(source + i))
	{
		if (*(source + i) == '"')
		{
			position = i;
		}

		i++;
	}

	return position;
}

char returnSymbol(char *symbols, size_t startPos, size_t symbolStep)
{
	size_t symbolPos = 2 * symbolStep;

	char symbol = *(symbols + startPos + symbolPos);

	return symbol;
}

void changeStr(char *source, char *dest)
{
	size_t counter = 0;
	size_t i = 0;
	size_t substringEnd = 0;
	char tempResult[MAX_SIZE];
	char x = ' ';
	char a = ' ';
	char b = ' ';

	substringEnd = findStrEnd(source);

	substring(source, tempResult, 0, substringEnd);

	x = returnSymbol(source, substringEnd, 1);
	a = returnSymbol(source, substringEnd, 2);
	b = returnSymbol(source, substringEnd, 3);

	while(*(tempResult + i))
	{
		if (*(tempResult + i) == x && !(counter & 1) )
		{
			*(dest + i) = a;
			counter++;
		}
		else if ( *(tempResult + i) == x && counter & 1 )
		{
			*(dest + i) = b;
			counter++;
		}
		else
		{
			*(dest + i) = *(tempResult + i);
		}

		i++;
	}

	*(dest + i) = '\0';
	i++;
}

void substring(char *source, char *dest, size_t beg, size_t end)
{
	size_t sourceLength = myStrlen(source);
	size_t endIndex = sourceLength - 1;
	size_t j = 0;

	if (sourceLength < beg || end < beg)
	{
		*dest = ' ';
		j++;
		*(dest + j) = '\0';
		return;
	}

	if (sourceLength > end)
	{
		endIndex = end;
	}

	for (size_t i = beg; i <= endIndex; ++i, ++j)
	{
		*(dest + j) = *(source + i);
	}

	*(dest + j) = '\0';
}