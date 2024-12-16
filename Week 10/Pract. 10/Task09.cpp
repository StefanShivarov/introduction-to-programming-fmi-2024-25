#include <iostream>

char *getLetters(int *firstArr, int *secondArr, const size_t LENGTH);
size_t getLetterQuantity(int *firstArr, int *secondArr, const size_t LENGTH);
bool isLetter(int firstNum, int secondNum);

const size_t MAX_SIZE = 10;

int main()
{
	int numbersFirst[MAX_SIZE] = {65, 12, 37, 100, 17, 55};
	int numbersSecond[MAX_SIZE] = {0, 66, 15, 1, 60, 2};
	size_t length = 6;

	char *result = getLetters(numbersFirst, numbersSecond, length);
	
	std::cout << result;

	delete[] result;
	return 0;
}

char *getLetters(int *firstArr, int *secondArr, const size_t LENGTH)
{
	size_t letters = getLetterQuantity(firstArr, secondArr, LENGTH);

	char *result = new char[letters + 1];
	size_t i = 0;
	size_t resultPos = 0;

	while (i < LENGTH)
	{
		bool letter = isLetter(*(firstArr + i), *(secondArr + i));

		if (letter)
		{
			*(result + resultPos) = (char)(*(firstArr + i) + *(secondArr + i));
			resultPos++;
		}

		i++;
	}
	*(result + resultPos) = '\0';
	resultPos++;

	return result;
}

size_t getLetterQuantity(int *firstArr, int *secondArr, const size_t LENGTH)
{
	size_t result = 0;
	size_t i = 0;

	while (i < LENGTH)
	{
		bool letter = isLetter(*(firstArr + i), *(secondArr + i));

		if (letter)
		{
			result++;
		}

		i++;
	}

	return result;
}

bool isLetter(int firstNum, int secondNum)
{
	int sum = firstNum + secondNum;
	if (sum >= 'A' && sum <= 'Z')
	{
		return 1;
	}

	if (sum >= 'a' && sum <= 'z')
	{
		return 1;
	}

	return 0;
}