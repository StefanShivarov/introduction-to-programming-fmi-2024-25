#include <iostream>

void strcpysmall(char *source, char *dest);

int main()
{
	const size_t MAX_SIZE = 30;
	char words[MAX_SIZE];
	char wordsResult[MAX_SIZE];

	std::cin.getline(words, MAX_SIZE);

	strcpysmall(words, wordsResult);
	std::cout << wordsResult << std::endl;
}

void strcpysmall(char *source, char *dest)
{
	size_t i = 0;
	size_t j = 0;

	while(*(source + i))
	{
		if (*(source + i) >= 'a' && *(source + i) <= 'z')
		{
			*(dest + j) = *(source + i);
			j++;
		}

		i++;
	}

	*(dest + j) = '\0';
	j++;
}