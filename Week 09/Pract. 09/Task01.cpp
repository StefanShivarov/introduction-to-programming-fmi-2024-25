#include <iostream>

size_t myStrlen(char *symbols);
void myStrcpy(char *source, char *dest);
void myStrcat(char *source, char *dest);

int main()
{
	const size_t MAX_SIZE = 30;
	char words[MAX_SIZE] = "Hello";
	char words1[MAX_SIZE] = "World";

	// std::cin.getline(words, MAX_SIZE);
	
	size_t wordsLength = myStrlen(words);
	std::cout << wordsLength << std::endl;

	myStrcat(words, " ");
	myStrcat(words, words1);
	std::cout << words << std::endl;

	char words2[MAX_SIZE];

	myStrcpy(words1, words2);
	std::cout << words2 << std::endl;
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

void myStrcpy(char *source, char *dest)
{
	size_t i = 0;

	while(*(source + i) && *(dest + i))
	{
		*(dest + i) = *(source + i);
		i++;
	}

	*(dest + i) = '\0';
	i++;
}

void myStrcat(char *dest, char *source)
{
	size_t i = myStrlen(dest);
	size_t j = 0;

	while(*(dest + j))
	{
		*(dest + i) = *(source + j);
		i++;
		j++;
	}

	*(dest + i) = '\0';
	i++;
}