#include <iostream>
using namespace std;


const int BEGINNING_BOUND = 65;
const int END_BOUND = 122;

//fill in an integer array =
void initialiseArray(int* arr, int size)
{
	if (arr == nullptr || size <= 0)
		return;

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

char* sumIntoLetters(int* arr1, int* arr2, int size)
{
	//invalid input
	if (arr1 == nullptr || arr2 == nullptr || size <= 0)
		return nullptr;

	//initialise result array
	char* result = new char[size + 1]; //for the \0
	result[size] = '\0';

	for (int i = 0; i < size; i++)
	{
		int currentSum = arr1[i] + arr2[i];
		//normalise if necessary
		if (currentSum > END_BOUND)
		{
			currentSum %= END_BOUND;
			currentSum += BEGINNING_BOUND - 1;
		}
		result[i] = (char)currentSum;
	}

	return result;
}

int main()
{
	//initialisation
	int size;
	cout << "Enter your size: ";
	cin >> size;
	while (size <= 0)
	{
		cout << endl << "Your size must be a whole positive integer. Please enter the size again: ";
		cin >> size;
	}

	int* arr1 = new int[size];
	int* arr2 = new int[size];

	cout << endl << "Please enter the numbers of your first array: ";
	initialiseArray(arr1, size);

	cout << endl << "Please enter the numbers of your second array: ";
	initialiseArray(arr2, size);

	//calculate and display result
	char* result = sumIntoLetters(arr1, arr2, size);
	cout << endl << result << endl;

	//housekeeping
	delete[] result;
	delete[] arr1;
	delete[] arr2;
	return 0;
}