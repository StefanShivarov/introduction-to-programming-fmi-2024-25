#include <iostream>

const size_t MAX_SIZE = 30;

void findEqualPrefix(char *first, char *second, char *third, char *result);

int main()
{
	char words[MAX_SIZE];
	char words1[MAX_SIZE];
	char words2[MAX_SIZE];
	char result[MAX_SIZE];

	std::cin >> words >> words1 >> words2;

	findEqualPrefix(words, words1, words2, result);

	std::cout << result;
}

void findEqualPrefix(char *first, char *second, char *third, char *result)
{
	size_t i = 0;
	size_t j = 0;

	while (*(first + i))
	{
		if (*(first + i) == *(second + i))
		{
			if (*(second + i) == *(third + i))
			{
				*(result + j) = *(first + i);
				j++;
			}
			else
			{
				*(result + j) = '\0';
				j++;
				return;
			}
		}
		else
		{
			*(result + j) = '\0';
			j++;
			return;
		}
	
	i++;
	}

	*(result + j) = '\0';
	j++;
}