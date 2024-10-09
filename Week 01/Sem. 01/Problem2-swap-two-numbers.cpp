/*
* Task:
*	Input: two numbers
*	Output: the numbers swapped
* Approach:
*	First Approach - using a third variable
*	Second approach - using arithmetics
*/

#include <iostream>
using namespace std;


int main()
{
	int num1, num2;
	cout << "This is a program that swaps the values of two number variables twice, using both the third-variable approach" <<
		"and the arithmetic approach." << endl;
	cout << "Please enter your two numbers: ";

	cin >> num1 >> num2;

	//first approach - swap using a third variable
	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "The values of your variables after the first swap are " << num1 << " and " << num2 << "." << endl;

	//second approach - using arithmetics
	num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;

	cout << "The values of your variables after the second swap are " << num1 << " and " << num2 << "." << endl;




	return 0;
}
