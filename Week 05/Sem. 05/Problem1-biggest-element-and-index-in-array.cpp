/*
* Task:
*	Input: an integer array (+ its size)
*	Output: the index and value of the biggest element in the array
* Approach:
*	Write a function which finds the biggest element via linear search. Use variables to remember its value and index.
*	These variables need to be passed to the function by reference. When the function finishes its execution, 
*	the variables will have the desired values.
* Notes:
*	It is considered bad practice to have a function that "returns" both ways - both via a return statement and utilising reference values.
*	When a function has to output more than 1 value, use references. Otherwise, use a return statement.
*/

#include <iostream>
using namespace std;

const int MAX_ARRAY_SIZE = 50;

void findBiggestElementInArray(int arr[], int arrSize, int& biggestElementValue, int& biggestElementIndex)
{
	if (arrSize <= 0)
		return; //wrong input - the array needs to have at least 1 element

	//initial initialization of the variables
	biggestElementValue = arr[0];
	biggestElementIndex = 0;

	//we begin the iteration from the second element because we have already assigned the first element values for the variables
	for (int i = 1; i < arrSize; i++)
	{
		//if we find a bigger element, update the values of the variables
		if (biggestElementValue < arr[i])
		{
			biggestElementValue = arr[i];
			biggestElementIndex = i;
		}
	}
}

//initialise your array - it is good practice. To test the max element algorithm you can hardcode your arrays
void initialiseArray(int arr[], int arrSize)
{
	if (arrSize <= 0)
		return;

	for (int i = 0; i < arrSize; i++)
	{
		cout << "Please enter the next element of your array: ";
		int temp = 0;
		cin >> temp;
		arr[i] = temp;
		cout << endl;
	}
}


int main()
{
	//initialisation
	int arrSize = 0;
	cout << "Please enter the size of your array - it must be smaller than or equal to " << MAX_ARRAY_SIZE << " ";
	cin >> arrSize;

	while (arrSize <= 0 || arrSize > MAX_ARRAY_SIZE)
	{
		cout << "You have entered an invalid value. Please enter a number between 1 and " << MAX_ARRAY_SIZE << " ";
		cin >> arrSize;
	}

	int arr[MAX_ARRAY_SIZE]{ 0 }; //makes an array full of 0s
	initialiseArray(arr, arrSize);

	//find the biggest element and its index
	int biggestElementValue = arr[0], biggestElementIndex = 0;
	findBiggestElementInArray(arr, arrSize, biggestElementValue, biggestElementIndex);

	//print the result
	cout << "The biggest element in the array is on index " << biggestElementIndex << " and its value is " << biggestElementValue << "." << endl;
}


