#include <iostream>
#include "StrUtils.h"
using namespace std;

/*
* Task:
*	Input: two char arrays - one message and one representing symbols to be censored
*	Output: a char array which contains the message with all censored symbols replaced by a star
* Approach:
*	Loop the message array. For every letter, check if it should be censored by looping through the array of censored symbols
*	It is true that this method is not very efficient, but it suffices for our level of knowledge. Don't worry, you'll learn other more efficient methods as you go through your uni education :D
*/


const char CENSOR_SYMBOL = '*';

//checks if a character needs to be censored
bool isInCensorList(char ch, const char* censorList)
{
	if (censorList == nullptr)
		return false;

	while (*censorList != '\0')
	{
		if (ch == *censorList)
			return true;
		
		censorList++;
	}

	return false;
}

char* censorMessage(const char* message, const char* censorList)
{
	//invalid input; please note that it is possible that the censoredList is empty, in which case nothing needs to be censored
	if (message == nullptr || myStrLen(message) <= 0)
		return nullptr;

	int messageLength = myStrLen(message);
	char* result = new char[messageLength + 1];
	result[messageLength] = '\0';

	if (censorList == nullptr || myStrLen(censorList) <= 0)
	{
		myStrCpy(result, message);
		return result;
	}

	for (int i = 0; i < messageLength; i++)
	{
		if (isInCensorList(message[i], censorList))
		{
			result[i] = CENSOR_SYMBOL;
		}
		else
		{
			result[i] = message[i];
		}
	}

	return result;
}

int main()
{
	char message[MAX_ARRAY_SIZE];
	cout << "Please enter your message: ";
	cin.getline(message, MAX_ARRAY_SIZE - 1);
	char censorList[MAX_ARRAY_SIZE];
	cout << endl << "Please enter your list of symbols to be censored: ";
	cin.getline(censorList, MAX_ARRAY_SIZE - 1);

	char* result = censorMessage(message, censorList);
	cout << endl << "Your censored message is: " << result << endl;

	delete[] result;
	return 0;
}