#include <iostream>

const size_t MAX_SIZE = 30;

char convertNumberToSymbol(size_t number);
void convertDecToKth(char *array, size_t number, size_t system);
void strcopyend(char *source, char *dest, int pos);

int main()
{
	char result[MAX_SIZE];
	size_t number = 0;

	std::cin >> number;
	convertDecToKth(result, number, 16);

	std::cout << result << std::endl;

	return 0;
}

char convertNumberToSymbol(size_t number)
{
	char symbol = ' ';

	if (number >= 0 && number <= 9)
	{
		return symbol = number + '0';
	}
	if (number > 9)
	{
		return symbol = number - 10 + 'A';
	}

	return symbol;
}

void convertDecToKth(char *array, size_t number, size_t system)
{
	char symbol = ' ';
	int i = 0;
	char tempResult[MAX_SIZE];

	while (number)
	{
		if (number >= system)
		{
			if (number % system)
			{
				symbol = convertNumberToSymbol(number % system);
				*(tempResult + i) = symbol;
				number -= number % system;
				number /= system;
				++i;
			}
			else
			{
				symbol = convertNumberToSymbol(0);
				*(tempResult + i) = symbol;
				number /= system;
				++i;
			}
		}
		else
		{
			symbol = convertNumberToSymbol(number);
			*(tempResult + i) = symbol;
			number = 0;
			++i;
		}
	}
	
	strcopyend(tempResult, array, i);

	*(tempResult + i) = '\0';
	i++;
}

void strcopyend(char *source, char *dest, int pos)
{
	size_t i = 0;
	pos--;

	while(pos >= 0)
	{
		*(dest + i) = *(source + pos);
		pos--;
		i++;
	}

	*(dest + i) = '\0';
	i++;
}