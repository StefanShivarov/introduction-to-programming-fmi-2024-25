/*
* Task:
*	Input: a whole positive integer
*	Output: a pyramid that looks like this:
*	1
*	1 2
*	1 2 3
* ...
*	1 2 3 ... n
*	where n is the input number
* Approach:
*	run a for loop from 1 to n. That signifies all the rows of the pyramid
*	Note that every row has as many numbers as the number of the row (1 for Row 1, 2 for Row 2, etc.)
*	For every row, print the numbers from 1 to the number of the row
*	Place a new line after every row
*/


#include <iostream>
using namespace std;
int main()
{
	int size;
	cout << "Enter the size of your pyramid: ";
	cin >> size;

	//the first loop represents the rows
	//notice that while it is customary for the counters in for loops to start at 0
	//this is a case in which it is okay to start at 1
	for (int i = 1; i <= size; i++)
	{
		//the second loop represents the numbers printed on every row
		for (int j = 1; j <= i; j++)
		{
			cout << j << " ";
		}
		//print a new line after every row
		cout << endl;
	}


	return 0;
}
