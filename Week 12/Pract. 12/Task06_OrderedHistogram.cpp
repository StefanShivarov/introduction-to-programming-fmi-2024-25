
#include <iostream>
#include "StrUtils.h"
using namespace std;

const char DELIMETER = ':';
const char SEPARATOR = ',';

//global vars
//for upper and lowercase letters
char letters[52];
int occurences[52];
int lettersIndex = 0, occurencesIndex = 0;

bool isInHistogram(char ch)
{
	for (int i = 0; i <= lettersIndex; i++)
	{
		if (ch == letters[i])
			return true;
	}

	return false;
}

int getHistogramIndex(char ch)
{
	for (int i = 0; i <= lettersIndex; i++)
	{
		if (ch == letters[i])
			return i;
	}

	return -1;
}

void fillHistogram(const char* input)
{
	int inputSize = myStrLen(input);
	for (int i = 0; i < inputSize; i++)
	{
		if (isInHistogram(input[i]))
		{
			int index = getHistogramIndex(input[i]);
			occurences[index]++;
		}
		else
		{
			letters[lettersIndex++] = input[i];
			occurences[occurencesIndex++] = 1;
		}
	}
}

char* getOrderedHistogram(const char* input)
{
	if (input == nullptr || myStrLen(input) == 0)
		return nullptr;

	fillHistogram(input);

	int resultLength = (lettersIndex + 1) * 6;
	char* result = new char[resultLength];
	result[resultLength - 1] = '\0';
	int resultIndex = 0;
	for (int i = 0; i <= lettersIndex; i++)
	{
		result[resultIndex++] = letters[i];
		result[resultIndex++] = DELIMETER;
		result[resultIndex++] = ' ';
		result[resultIndex++] = (char)occurences[i] + '0';
		if (i == lettersIndex)
		{
			result[resultIndex++] = '\0';
		}
		else
		{
			result[resultIndex++] = SEPARATOR;
			result[resultIndex++] = ' ';
		}
	}

	return result;
}

int main()
{
	char input[MAX_ARRAY_SIZE];
	cout << "Please enter your input: ";
	cin.getline(input, MAX_ARRAY_SIZE - 1);

	char* result = getOrderedHistogram(input);
	cout << result << endl;

	delete[] result;
	return 0;
}

