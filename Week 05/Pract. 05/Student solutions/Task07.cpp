#include <iostream>

void fillArray(int* array, const int SIZE)
{
 for (int i = 0; i < SIZE; ++i)
 {
  std::cin >> array[i];
 }
}

void swapArrayValues(int* array, const int SIZE, const int FIRST_INDEX, const int SECOND_INDEX, int& minValue)
{
 minValue = array[SECOND_INDEX];
 int swap = array[FIRST_INDEX];
 array[FIRST_INDEX] = array[SECOND_INDEX];
 array[SECOND_INDEX] = swap;
}

bool checkEven(int value, bool flag)
{
 if (!(flag))
 {
  return value % 2 != 0;
 }
 return value % 2 == 0;
}

void sortEvenOdd(int* array, const int SIZE, bool even = 0)
{
 for (int i = 0; i < SIZE; ++i)
 {
  int minValue = array[i];
  for (int j = i + 1; j < SIZE; ++j)
  {
   bool checkMinValue = checkEven(minValue, even);
   bool checkArray = checkEven(array[j], even);
   if (checkMinValue)
   {
    if (minValue > array[j] && checkArray)
    {
     swapArrayValues(array, SIZE, i, j, minValue);
    }
   }
   else
   {
    if (checkArray)
    {
     swapArrayValues(array, SIZE, i, j, minValue);
    }
   }
  }
 }
}

void printArray(int* array, int SIZE)
{
 for (int i = 0; i < SIZE; ++i)
 {
  std::cout << array[i] << " ";
 }
}

void main()
{
 int numbersQuantity = 0;
 const unsigned int MAX_SIZE = 15;
 int numbers[MAX_SIZE];

 std::cin >> numbersQuantity;
 fillArray(numbers, numbersQuantity);

 sortEvenOdd(numbers, numbersQuantity);
 sortEvenOdd(numbers, numbersQuantity, 1);
 printArray(numbers, numbersQuantity);

}