#include <iostream>
using namespace std;

void findMinMax(const int *arr, int size, int &minValue, int &maxValue)
{
    minValue = arr[0];
    maxValue = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minValue)
            minValue = arr[i];
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }
}

int main()

{
    int arr[] = {4, 7, 5, 8, 1};
    int size = 5;
    int minvalue = 0;
    int maxValue = 0;
    findMinMax(arr, size, minvalue, maxValue);
    cout << minvalue << maxValue;
    return 0;
}