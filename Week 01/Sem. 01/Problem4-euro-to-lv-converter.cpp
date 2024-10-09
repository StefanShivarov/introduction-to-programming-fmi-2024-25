/*
* Task:
*	Input: an amount in euro
*	Output: the same amount of money in stotinki, rounded to the second digit after the decimal mark
* Approach: 
	1 euro is 196 st
Pittfals:
	Euro can be a double value
	Use fixed + setpresicion(2) to round to the second digit after the decimal mark
*/

#include <iostream>
#include <iomanip> //contains setpresicion function
using namespace std;

int main()
{
	cout << "Enter your amount in Euro: ";
	double euroAmount;
	cin >> euroAmount;

	double stAmount = euroAmount * 196;
	cout << "The amount in st is " << fixed << setprecision(2) << stAmount << endl;


	return 0;
}