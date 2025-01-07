#include <iostream>
#include "StrUtils.h"
using namespace std;

/*
* Task:
*	Input: a char array
*	Output: a char array containing only the first and last letters of every word
*		If a word only has one letter, that one letter is added to the array
* Approach:
*	Run a loop to find the number of symbols you'll need for your result array
*	(don't forget that your result array must be dynamic in order for you to return it!)
*	Then run a different loop and add the symbols
*/


bool isLetter(char ch)
{
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

bool isWhitespace(char ch)
{
	return ch == ' ';
}

bool isFirstLetter(const char* input, int inputIndex)
{
	if (inputIndex == 0 && isLetter(input[inputIndex]))
	{
		return true;
	}

	else if (inputIndex > 0 && isWhitespace(input[inputIndex - 1]) && isLetter(input[inputIndex]))
		return true;

	return false;
}

bool isLastLetter(const char* input, int inputIndex)
{
	if (inputIndex == myStrLen(input) - 1 && isLetter(input[inputIndex]))
		return true;

	else if (inputIndex < myStrLen(input) - 1 && isLetter(input[inputIndex]) && isWhitespace(input[inputIndex + 1]))
		return true;

	return false;
}

bool isOneLetterWord(const char* input, int inputIndex)
{
	return isFirstLetter(input, inputIndex) && isLastLetter(input, inputIndex);
}

int findLengthOfResultChar(const char* input)
{
	if (input == nullptr || *input == '\0')
		return 0; //input is empty

	int inputLength = myStrLen(input);
	int inputIndex = 0;
	int result = 0;

	while (input[inputIndex] != '\0')
	{
		if (isOneLetterWord(input, inputIndex))
		{
			result++;
		}
		else if (isFirstLetter(input, inputIndex))
		{
			result++;
		}
		else if (isLastLetter(input, inputIndex))
		{
			result++;
		}
		else if (isWhitespace(input[inputIndex]))
		{
			result++;
		}

		inputIndex++;
	}

	return result + 1; //for the \0
}

char* getFirstAndLastLetters(const char* input)
{
	int resultLength = findLengthOfResultChar(input);
	int inputLength = myStrLen(input);
	char* result = new char[resultLength];
	result[resultLength - 1] = '\0';
	result[0] = input[0]; //copy first letters

	int resultIndex = 1, inputIndex = 1;
	for (; resultIndex < resultLength && inputIndex < inputLength; inputIndex++)
	{
		if (isOneLetterWord(input, inputIndex))
		{
			result[resultIndex++] = input[inputIndex];
		}
		else if (isFirstLetter(input, inputIndex))
		{
			result[resultIndex++] = input[inputIndex];
		}
		
		else if (isLastLetter(input, inputIndex))
		{
			result[resultIndex++] = input[inputIndex];
		}
		else if (isWhitespace(input[inputIndex]))
		{
			result[resultIndex++] = input[inputIndex];
		}
		else
			continue;
	}

	return result;
}

int main()
{
	char input[MAX_ARRAY_SIZE];
	cout << "Please enter your input: ";
	cin.getline(input, MAX_ARRAY_SIZE - 1);

	char* result = getFirstAndLastLetters(input);
	cout << result;

	delete[] result;
	return 0;
}