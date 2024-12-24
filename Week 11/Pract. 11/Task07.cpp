#include <iostream>

const size_t MAX_SIZE = 4;
const size_t MAX_STRING_SIZE = 40;
void myStrcpy(char *source, char *dest);
size_t myStrlen(char *symbols);
char *modifyString(char *array);
size_t findSpace(char *array, bool last = 0);
size_t findFirstSpace(char *array);

int main()
{
	char symbols[MAX_STRING_SIZE];
	
	std::cout << "Please enter your phrase: ";
	std::cin.getline(symbols, MAX_STRING_SIZE);

	char* result = modifyString(symbols);

	std::cout << result;

	delete[] result;

	return 0;
}

void myStrcpy(char *source, char *dest)
{
	size_t i = 0;

	while(*(source + i))
	{
		*(dest + i) = *(source + i);
		i++;
	}

	*(dest + i) = '\0';
	i++;
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

char *modifyString(char *array)
{
	if (array == nullptr)
	{
		return nullptr;
	}

	size_t arrayLength = myStrlen(array);
	size_t firstSpacePos = findSpace(array);
	size_t lastSpacePos = findSpace(array, 1);
	size_t resultLength = 0;

	if (!firstSpacePos || firstSpacePos == lastSpacePos)
	{
		resultLength = arrayLength + 1;
		char *result = new char[resultLength];
		myStrcpy(array, result);
		return result;
	}

	resultLength = firstSpacePos + arrayLength - lastSpacePos + 1;
	char *result = new char[resultLength];
	
	size_t i = 0;

	for (i = 0; i < firstSpacePos; ++i)
	{
		*(result + i) = *(array + i);
	}

	size_t resultPosition = i;

	for (i = lastSpacePos; i < arrayLength; ++i)
	{
		*(result + resultPosition) = *(array + i);

		resultPosition++;
	}

	return result;
}

size_t findSpace(char *array, bool last)
{
	size_t i = 0;
	char space = ' ';
	bool isSpace = 0;

	if (last)
	{
		size_t currentSpacePosition = 0;
		size_t lastWordSpace = 0;

		while(*(array + i))
		{
			if(*(array + i) >= 'a' && *(array + i) <= 'z')
			{
				if(isSpace)
				{
					isSpace = 0;
					lastWordSpace = currentSpacePosition;
				}
			}

			if(*(array + i) >= 'A' && *(array + i) <= 'Z')
			{
				if(isSpace)
				{
					isSpace = 0;
					lastWordSpace = currentSpacePosition;
				}
			}

			if(*(array + i) == space && !isSpace)
			{
				currentSpacePosition = i;
				isSpace = 1;
			}
			else if(*(array + i) == space && isSpace)
			{
				currentSpacePosition = i;
			}

			i++;
		}

		return lastWordSpace;
	}

	size_t result = findFirstSpace(array);
	return result;
}


size_t findFirstSpace(char *array)
{
	size_t i = 0;
	char space = ' ';
	bool isLetter = 0;

	while(*(array + i))
	{

		if(*(array + i) >= 'a' && *(array + i) <= 'z')
		{
			if(!isLetter)
			{
				isLetter = 1;
			}
		}

		if(*(array + i) >= 'A' && *(array + i) <= 'Z')
		{
			if(!isLetter)
			{
				isLetter = 1;
			}
		}

		if (isLetter && *(array + i) == space)
		{
			return i;
		}

		i++;
	}
}