/*
* Task:
*	Input: a large whole number
*	Output: print only the digits of the number which are on even positions when read from left to right
*	(note: usually number positions are read from right to left, but in this case we will count from left to right)
* Approach:
*	- reverse the number
*	- remove the last digit of the reversed number - it corresponds to the first digit of the input number and is therefore never printed
*	- print every second digit of the reversed number, starting with the new last one
*	- that way we print only the digits on even positions in the input number
*	
*/

#include <iostream>
using namespace std;

int main()
{
	long long number;
	cout << "Please enter your number: ";
	cin >> number;

	long long numberCopy = number;
	long long reversedNumber = 0;
	long long digitCounter = 0;

	//reverse the number and keep count of how many digits it has
	while (numberCopy != 0)
	{
		(reversedNumber *= 10) += (numberCopy % 10);
		numberCopy /= 10;
		digitCounter++;
	}

	//remove the last digit of the reversed number
		reversedNumber /= 10;
		digitCounter--;
	
	//print every second digit of the reversed number, starting with the last one (it corresponds to the second digit of the input number)
	for (int i = 0; i < digitCounter; i++)
	{
		if (i % 2 == 0)
		{
			//print the last digit
			cout << reversedNumber % 10;
		}
		else
		{
			//skip it - print a blank space
			cout << " ";
		}
		//remove the last digit
		reversedNumber /= 10;
	}

	return 0;
}