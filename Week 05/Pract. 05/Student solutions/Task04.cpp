#include <iostream>

void fillArray(int* array, const int SIZE)
{
 for (int i = 0; i < SIZE; ++i)
 {
  std::cin >> array[i];
 }
}

bool isSame(int* firstArray, int* secondArray, const int SIZE)
{
 for (int i = 0; i < SIZE; ++i)
 {
  if (firstArray[i] != secondArray[i])
  {
   return 0;
  }
 }

 return 1;
}

void sortArray(int* array, const int SIZE)
{
 for (int i = 0; i < SIZE - 1; ++i)
 {
  int minValue = array[i];

  for (int j = i + 1; j < SIZE; ++j)
  {
   if (array[j] < minValue)
   {
    minValue = array[j];
    int swap = array[i];
    array[i] = minValue;
    array[j] = swap;
   }
  }
 }
}

bool isPermutation(int* firstArray, int* secondArray, const int SIZE)
{
 bool sameArray = isSame(firstArray, secondArray, SIZE);

 if (!(sameArray))
 {
  sortArray(firstArray, SIZE);
  sortArray(secondArray, SIZE);
  sameArray = isSame(firstArray, secondArray, SIZE);

  if (sameArray)
  {
   return 1;
  }
 }

 return 0;
}

void main()
{
 int numbersQuantity = 0;
 const unsigned int MAX_SIZE = 15;
 int numbersFirst[MAX_SIZE];
 int numbersSecond[MAX_SIZE];

 std::cin >> numbersQuantity;
 fillArray(numbersFirst, numbersQuantity);
 fillArray(numbersSecond, numbersQuantity);

 bool permutation = isPermutation(numbersFirst, numbersSecond, numbersQuantity);

 if (permutation)
 {
  std::cout << "true";
 }
 else
 {
  std::cout << "false";
 }
}