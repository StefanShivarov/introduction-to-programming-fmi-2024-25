#include <iostream>

const size_t MAX_SIZE = 30;

void eraseRepeating(char *symbols, char *result);

int main()
{
	char words[MAX_SIZE];
	char result[MAX_SIZE] = "\0";

	std::cin >> words;

	eraseRepeating(words, result);

	std::cout << result;
}

void eraseRepeating(char *symbols, char *result)
{
	size_t i = 0;

	while (*(symbols + i))
	{
		size_t j = 0;
		bool exist = 0;

		while(*(result + j))
		{
			if (*(symbols + i) == *(result + j))
			{
				exist = 1;
			}

			j++;
		}

		if (!exist)
		{
			*(result + j) = *(symbols + i);
			j++;
			*(result + j) = '\0';
		}

		i++;
	}
}