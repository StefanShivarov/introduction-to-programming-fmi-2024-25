#include <iostream>

const size_t MAX_SIZE = 50;

size_t myStrlen(char *symbols);
void hideString(char *string, char *substring, char *result, char change);
bool compareSymbols(char symbol, char secondSymbol);
char lowerize(char symbol);

int main()
{
	char string[MAX_SIZE] = "Howdy! How are you? How was your day?";
	char substring[MAX_SIZE] = "how";
	char result[MAX_SIZE] = "\0";
	char asterisk = '*';

	// std::cin >> words >> substring;
	hideString(string, substring, result, asterisk);

	std::cout << result;
}

void hideString(char *string, char *substring, char *result, char change)
{
	size_t i = 0;
	size_t substringLength = myStrlen(substring);

	while (*(string + i))
	{
		size_t j = 0;
		bool different = 0;

		while(*(substring + j))
		{
			bool compare = compareSymbols(*(string + i + j), *(substring + j));

			if (!compare)
			{
				different = 1;
			}

			j++;
		}

		if (!different)
		{
			j = 0;

			while(*(substring + j))
			{
				*(result + i + j) = change;
				j++;
			}

			i += j;
			
		}
		else
		{
			*(result + i) = *(string + i);
			i++;
			*(result + i) = '\0';
		}
	}
}

bool compareSymbols(char symbol, char secondSymbol)
{
	char lowerizedFirst = lowerize(symbol);
	char lowerizedSecond = lowerize(secondSymbol);

	if (lowerizedFirst != lowerizedSecond)
	{
		return 0;
	}

		return 1;
}

char lowerize(char symbol)
{
	if (symbol >= 'A' && symbol <= 'Z')
	{
		symbol = symbol - 'A' + 'a';
	}

	return symbol;
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