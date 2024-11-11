#include <iostream>

void fillArray(int* array, const int SIZE)
{
 for (int i = 0; i < SIZE; ++i)
 {
  std::cin >> array[i];
 }
}

bool isSubArray(int* firstArray, int SIZE_FIRST, int* secondArray, const int SIZE_SECOND)
{
 for (int i = 0; i < SIZE_FIRST; i++)
 {
  if (firstArray[i] == secondArray[0] && i + SIZE_SECOND <= SIZE_FIRST)
  {
   for (int j = 0; j < SIZE_SECOND; ++j)
   {
    if (firstArray[i+j] != secondArray[j])
    {
     break;
    }
    if ( j == SIZE_SECOND - 1)
    {
     return 1;
    }
   }
  }
 }

 return 0;
}

void main()
{
 int numbersFirstQuantity = 0;
 int numbersSecondQuantity = 0;
 const unsigned int MAX_SIZE = 15;
 int numbersFirst[MAX_SIZE];
 int numbersSecond[MAX_SIZE];

 std::cin >> numbersFirstQuantity;
 fillArray(numbersFirst, numbersFirstQuantity);
 
 std::cin >> numbersSecondQuantity;
 fillArray(numbersSecond, numbersSecondQuantity);

 bool subArray = isSubArray(numbersFirst, numbersFirstQuantity, numbersSecond, numbersSecondQuantity);

 if (subArray)
 {
  std::cout << "true";
 }
 else
 {
  std::cout << "false";
 }
}