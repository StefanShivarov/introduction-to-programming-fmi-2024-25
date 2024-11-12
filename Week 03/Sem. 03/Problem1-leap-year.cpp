/*
* Task:
*	Input - an integer representing a year
*	Output - bool: whether the year is a leap year or not
* Approach:
*	To test whether a year is a leap one, we need to perform the following calculations:
*	If a year is not divisible by 4, then it is not a leap one.
*	If it is divisible by 4 and is not divisible by 100, then it is a leap one.
*	If it is divisible by 4 and by 100, we need to check whether it is divisible by 400:
*		- if it is, then the year is leap
*		- if it isn't, then the year is not leap.
* Notes:
*	This approach might be hard to understand. For now, accept that this is the algorithm which checks for leap years or ask during seminars/practicums for the mathematical explanation
*/

#include <iostream>
using namespace std;


bool isLeap(int year)
{	
	//check if the year is divisible by 4
	if (year % 4 == 0)
	{
		//if year is divisible by 4 but not by 100, then it is leap
		if (year % 100 != 0)
			return true;
		//if year is divisible by 4 and by 100, it is only leap if it is divisible by 400
		else if (year % 400 == 0)
			return true;
		else
			return false;
	}
	//if year is not divisible by 4, then it is not leap
	return false;
}

int main()
{
	cout << "Please enter a year: " << endl;
	int year;
	cin >> year;

	bool isLeapYear = isLeap(year);
	if (isLeapYear)
	{
		cout << year << " is a leap year." << endl;
	}
	else
	{
		cout << year << " is not a leap year." << endl;
	}

	return 0;
}
