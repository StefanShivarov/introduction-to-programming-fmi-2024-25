#include <iostream>

void absolute(int& value)
{
 if (value < 0) {
  value *= -1;
 }
}

void fillArray(int* array, const int SIZE)
{
 for (int i = 0; i < SIZE; ++i)
 {
  std::cin >> array[i];
 }
}

int* diffNeighbourElements(int* arrayData, int* resultArray, const int SIZE)
{
 for (int i = 0; i < SIZE; ++i)
 {
  resultArray[i] = arrayData[i] - arrayData[i+1];
 }

 return resultArray;
}

void printArray(int* array, const int SIZE)
{
 for (int i = 0; i < SIZE; ++i)
 {
  std::cout << array[i] << " ";
 }
}

void main()
{
 int numbersQuantity = 0;
 int sumsQuantity = 0;
 const unsigned int MAX_SIZE = 15;
 int numbersData[MAX_SIZE];
 int sumsEmpty[MAX_SIZE];

 std::cin >> numbersQuantity;
 sumsQuantity = numbersQuantity - 1;

 fillArray(numbersData, numbersQuantity);
 int* sumArray = diffNeighbourElements(numbersData, sumsEmpty, sumsQuantity);

 for (int i = 0; i < sumsQuantity; ++i)
 {
  absolute(sumArray[i]);
 }

 printArray(sumArray, sumsQuantity);
}