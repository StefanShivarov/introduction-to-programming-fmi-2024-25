/*
* Task:
*	Input: a whole number
*	Output: boolean - if a number is divisble by 3 without using the % operator
* Approach:
*	Divide the number by 3. Multiple the result by 3. Check if the two numbers are equal.
*	Question for you - why does this work?
* Additional Notes:
*	This is only one approach to this problem. There are multiple possible correct solutions.
*/


#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "Enter a number: " << endl;
	cin >> number;

	int newNumber = number / 3;
	newNumber *= 3;

	if (newNumber == number)
	{
		cout << number << " is divisible by 3." << endl;
	}
	else
	{
		cout << number << " is not divisible by 3." << endl;
	}
}
