#include <iostream>

size_t myStrlen(char *symbols);
void substring(char *source, char *dest, size_t beg, size_t end);

int main()
{
	const size_t MAX_SIZE = 30;
	char words[MAX_SIZE];
	char subWords[MAX_SIZE] = " ";

	size_t beg = 0;
	size_t end = 0;

	std::cin >> words >> beg >> end;

	substring(words, subWords, beg, end);

	std::cout << subWords;
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