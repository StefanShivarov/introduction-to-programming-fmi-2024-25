/*
* Task:
*	Input: a whole number
*	Output: the sum of the digits of the number
* Approach:
*	While the number is different than zero, take the last number with %10 and add it to the total.
*	Then divide the number by 10 to remove the last digit
*/


#include <iostream>
using namespace std;

int main()
{
	//initialize number
	long long number;
	cout << "Please enter your number: ";
	cin >> number;

	long long sum = 0;
	long long numberCopy = number; //it is a good practice to copy input data if you are going to change it
	//and change the copy instead. That way you have the original data intact in case you need it later

	//repeat actions inside loop body until number equals 0
	while (numberCopy != 0)
	{
		//take the current last digit of the number
		int currentLastDigit = numberCopy % 10;

		//add it to the total sum
		sum += currentLastDigit;

		//divide the number by 10;
		numberCopy /= 10;
	}

	cout << "The sum of the digits of " << number << " is " << sum << endl;
	return 0;
}
