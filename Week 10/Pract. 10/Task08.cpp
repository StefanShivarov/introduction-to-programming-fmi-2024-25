#include <iostream>

size_t getFirstWordLength(char *tlate);
int positionInTlate(char *tlate, const size_t LENGTH, char symbol);
size_t mystrlen(char *symbols);
char *rewrite(char *sentence, char *tlate);

int main()
{
	const size_t LENGTH = 40;
	char sentence[LENGTH] = { '\0' };
	char tlate[LENGTH] = { '\0' };

	std::cin.getline(sentence, LENGTH);
	std::cin.getline(tlate, LENGTH);

	char *result = rewrite(sentence, tlate);

	std::cout << result;

	delete[] result;
}

size_t getFirstWordLength(char *arr)
{
	char space = ' ';
	size_t i = 0;

	while (*(arr + i) != space)
	{
		i++;
	}

	return i;
}

int positionInTlate(char *arr, const size_t LENGTH, char symbol)
{
	for (int i = 0; i < LENGTH; ++i)
	{
		if (*(arr + i) == symbol)
		{
			return i;
		}
	}

	return -1;
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

char *rewrite(char *sentence, char *tlate)
{
	size_t i = 0;

	size_t tlateWordLength = getFirstWordLength(tlate);
	size_t sentenceLength = mystrlen(sentence);

	char *result = new char[sentenceLength + 1];

	while (*(sentence + i))
	{
		int symbolPosition = positionInTlate(tlate, tlateWordLength, *(sentence + i));

		if (symbolPosition > -1)
		{
			*(result + i) = *(tlate + symbolPosition + 1 + tlateWordLength);
		}
		else
		{
			*(result + i) = *(sentence + i);
		}

		i++;
	}

	*(result + i) = '\0';
	i++;

	return result;
}