#include <iostream>

bool ifTriangle(int* array)
{
 int firstSide = array[0];
 int secondSide = array[1];
 int thirdSide = array[2];

 if (firstSide > 0 && secondSide > 0 && thirdSide > 0 )
 {
  if (firstSide + secondSide < thirdSide )
  {
   return 0;
  }

  if (firstSide + thirdSide < secondSide )
  {
   return 0;
  }

  if (thirdSide + secondSide < firstSide )
  {
   return 0;
  }
  
  return 1;
 }
 return 0;
}

void fillTriangleSides(int (*array)[3], int& size, int (*resultArray)[3])
{
 int resultIncrement = 0;

 for (int i = 0; i < size; ++i)
 {
  bool triangleSide = ifTriangle(array[i]);

  if (triangleSide)
  {
   resultArray[resultIncrement][0] = array[i][0];
   resultArray[resultIncrement][1] = array[i][1];
   resultArray[resultIncrement][2] = array[i][2];
   ++resultIncrement;
  }
 }

 size = resultIncrement;
}

void fillArray(int (*array)[3], const int SIZE)
{
 for (int i = 0; i < SIZE; ++i)
 {
  for (int j = 0; j < 3; ++j)
  {
   std::cin >> array[i][j];
  }
 }
}

void printArray(int (*array)[3], int MAX_SIZE)
{
 for (int i = 0; i < MAX_SIZE; ++i)
 {
  for (int j = 0; j < 3; ++j)
  {
   std::cout << array[i][j] << " ";
  }
  std::cout << std::endl;
 }
}

void main()
{
 const unsigned int MAX_SIZE = 10;
 const unsigned int MAX_COL_SIZE = 3;
 int numbersData[MAX_SIZE][MAX_COL_SIZE];
 int triangleSides[MAX_SIZE][MAX_COL_SIZE];
 int arraySize = 0;
 int resultArraySize = 0;

 std::cin >> arraySize;
 resultArraySize = arraySize;

 fillArray(numbersData, arraySize);

 fillTriangleSides(numbersData, resultArraySize, triangleSides);

 std::cout << "Matrix with triangle sides sizes:" << std::endl;

 printArray(triangleSides, resultArraySize);
}