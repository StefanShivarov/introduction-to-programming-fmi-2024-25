#include <iostream>

void fillArray(int* array, const int SIZE)
{
 for (int i = 0; i < SIZE; ++i)
 {
  std::cin >> array[i];
 }
}

void unify(int* firstArray, const int FIRST_SIZE, int* secondArray, const int SECOND_SIZE, int* resultArray, int& resultSize)
{
 int totalSize = FIRST_SIZE * SECOND_SIZE;
 int counterFirst = 0;
 int counterSecond = 0;

 for (int i = 0; i < FIRST_SIZE; ++i)
 {
  resultArray[i] = firstArray[i];
  ++resultSize;
 }

 for (int i = 0; i < totalSize; ++i)
 {
  if (resultArray[counterFirst] == secondArray[counterSecond] )
  {
   i += FIRST_SIZE - counterFirst - 1;
   counterFirst = 0;
   ++counterSecond;
   continue;
  }
  ++counterFirst;
  counterFirst %= FIRST_SIZE;

  if (!(i % FIRST_SIZE) && i)
  {
   resultArray[resultSize] = secondArray[counterSecond];
   ++resultSize;
  }

  if (!(i % SECOND_SIZE) && i)
  {
   ++counterSecond;
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
 int numbersFirstQuantity = 0;
 int numbersSecondQuantity = 0;
 int numbersResultQuantity = 0;
 const unsigned int MAX_SIZE = 15;
 int numbersFirst[MAX_SIZE];
 int numbersSecond[MAX_SIZE];
 int numbersResult[MAX_SIZE];

 std::cin >> numbersFirstQuantity;
 fillArray(numbersFirst, numbersFirstQuantity);

 std::cin >> numbersSecondQuantity;
 fillArray(numbersSecond, numbersSecondQuantity);
 
 unify(numbersFirst, numbersFirstQuantity, numbersSecond, numbersSecondQuantity, numbersResult, numbersResultQuantity);

 printArray(numbersResult, numbersResultQuantity);
}
