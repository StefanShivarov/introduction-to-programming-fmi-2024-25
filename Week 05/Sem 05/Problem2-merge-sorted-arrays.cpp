/*
* Task: 
*	Input: 2 sorted arrays of size 8. The arrays must have unique members (though duplicates in the different arrays are allowed)
*		and must not have 0 as an element.
*	Output: an array of size 16 which combines the 2 sorted arrays into a single array which is also sorted. If there are any duplicate
*		elements, the duplicate element is only written in the array once. The array is padded with 0s if its total number of
*		elements is less than 16.
* Approach:
*	Create separate indexes with which you will iterate your two arrays. Iterate the two arrays at the same time (in one loop statement).
	Copy the current smaller member of the arrays and increase the coresponding index. If the elements are equal, copy the element
	only once but increase both indexes to skip the duplicate.
*	Once you've exited your loop, one of the arrays must have finished. You do not need to check which one it is - simply try to
*	iterate both until they're done. Since one of them has been traversed in full, its index would have reached the position (size - 1)
*	and it would simply not enter any loop statement intended to traverse it further.
* Notes:
*	The algorithm is explained in full in the problem task
*/

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 8;

//fill an array with values from the standard input
void initArray(int* arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << "Please enter an element of your array: ";
		int temp = 0;
		cin >> temp;
		arr[i] = temp;
	}
}

//print an array
void printArray(int* arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void mergeSortedArrays(int arr1[], int arr2[], int result[], int arr1Size, int arr2Size, int resultSize)
{
	//initialization of result array and indexes for both arrays
	int index1 = 0, index2 = 0, indexResult = 0;

	//traverse both arrays simultaneously
	while (index1 < arr1Size && index2 < arr2Size)
	{
		//if the current element in the first array is smaller than the current element in second array, 
		//take the smaller and move the index
		if (arr1[index1] < arr2[index2])
		{
			result[indexResult++] = arr1[index1++];
		}
		//the same procedure happens if the current element in the second array is smaller
		else if (arr2[index2] < arr1[index1])
		{
			result[indexResult++] = arr2[index2++];
		}
		//if the elements are equal, take one and skip the element in the other array
		else
		{
			result[indexResult++] = arr1[index1++];
			index2++;
		}
	}

	/*if we've broken out of the above while, then either index1 is not equal to arr1Size, or index2 is equal to arr2Size
	* Regardless of whichever has happened, we can assume that at least one array has remaining elements
	* in which case its index will still be smaller than its array size
	* so we must traverse it until the end
	* We can try to traverse both using the same method - in that case the array which has already been traversed in full
	* will not satisfy the while contidion and will not enter the array
	* whereas the remaining one will and its elements will be copied
	* So it does not matter which array remains
	*/

	while (index1 < arr1Size)
	{
		result[indexResult++] = arr1[index1++];
	}

	while (index2 < arr2Size)
	{
		result[indexResult++] = arr2[index2++];
	}
}



int main()
{
	//initialisation
	int sortedArray1[ARRAY_SIZE]{ 0 }, sortedArray2[ARRAY_SIZE]{ 0 };
	cout << "Initialising the first array: " << endl;
	initArray(sortedArray1, ARRAY_SIZE);
	cout << "Initialising the second array: " << endl;
	initArray(sortedArray2, ARRAY_SIZE);

	printArray(sortedArray1, ARRAY_SIZE);
	printArray(sortedArray2, ARRAY_SIZE);

	//create the result array
	int resultArray[ARRAY_SIZE * 2]{ 0 };

	//merge the two arrays into the result array and print the result array
	mergeSortedArrays(sortedArray1, sortedArray2, resultArray, ARRAY_SIZE, ARRAY_SIZE, ARRAY_SIZE * 2);
	printArray(resultArray, ARRAY_SIZE * 2);
}