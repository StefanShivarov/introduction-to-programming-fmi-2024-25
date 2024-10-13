/*
* Task:
*	Input: 3 whole numbers
*	Output: the 3 numbers sorted in ascending order (from the smallest one to the largest one)
* Approach:
*	This problem can be solved using just 3 if statements.
*	Fist, check if the first number is bigger than the second.
*	Then, check if the second number is bigger than the third;
*	Last, check if the first number is bigger than the second.
* Additional Notes:
*	- This is only one possible solutions. There are more 3-if combinations that will work.
*	- if you swap the > for < in the checks, you will receive a sort in descending order (from the largest to the smallest)
*/


#include <iostream>
using namespace std;
int main()
{
	int number1, number2, number3;
	cout << "Please enter your 3 numbers: ";
	cin >> number1 >> number2 >> number3;

	if (number1 > number2)
	{
		//swapping using a third variable
		int temp = number1;
		number1 = number2;
		number2 = temp;
	}

	//note - do not use if-else! The 3 ifs should be independent
	if (number2 > number3)
	{
		//swapping without a third variable - usually not a good practice, I'm putting it here just to show it
		number2 = number2 + number3;
		number3 = number2 - number3;
		number2 = number2 - number3;
	}

	if (number1 > number2)
	{
		int temp = number1;
		number1 = number2;
		number2 = temp;
	}

	cout << "Your sorted numbers are " << number1 << " " << number2 << " " << number3 << "." << endl;



	return 0;
}
