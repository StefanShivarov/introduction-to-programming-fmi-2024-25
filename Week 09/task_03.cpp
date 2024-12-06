#include <iostream>
using namespace std;
const int MAX_SIZE = 50;

int lenght(char* arr, int beg, int end, int lenght = 0)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		lenght++;
		i++;
	}
	if (beg > lenght)
	{
		return -1;
	}
	return 0;

}

int PrintResult(char arr[], char result[], int beg, int end)
{
	int i = 0;
	int j = 0;
	while (arr[i] != '\0')
	{
		if (i<beg || i>end)
		{
			i++;
		}
		else
		{

			result[j] = arr[i];
			j++;
			i++;
		}
	}
	result[j] = '\0';
	cout << result;
	return 0;

}

int main()
{
	char arr[MAX_SIZE], result[MAX_SIZE];
	cin >> arr;

	int beg, end;
	cin >> beg;
	cin >> end;
	if (beg > end)
	{
		return -1;
	}
	lenght(arr, beg, end);
	PrintResult(arr, result, beg, end);
	return 0;


}

