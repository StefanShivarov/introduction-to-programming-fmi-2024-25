#include <iostream>

void fillArray(char (*array)[10], const int SIZE)
{
 for (int i = 0; i < SIZE; ++i)
 {
  for (int j = 0; j < SIZE; ++j)
  {
   std::cin >> array[i][j];
  }
 }
}

bool areRowsMagic(char (*array)[10], const int MAX_SIZE, bool rows = 1)
{
 for (int i = 0; i < MAX_SIZE; ++i)
 {
  for (int j = 0, k = MAX_SIZE - 1; j < MAX_SIZE; ++j, --k)
  {
   if (rows)
   {
    if (array[i][j] != array[i][k])
    {
     return 0;
    }
   }
   else
   {
    if (array[j][i] != array[k][i])
    {
     return 0;
    
    }
   }
  }
 }

 return 1;
}

bool areDiagMagic(char (*array)[10], const int MAX_SIZE)
{
 for (int i = 0, j = MAX_SIZE - 1; i < MAX_SIZE; ++i, j--)
 {
  if (array[i][i] != array[j][i])
  {
   return 0;
  }
 }

 return 1;
}

bool isMagic(char (*array)[10], const int MAX_SIZE)
{
 bool rows = areRowsMagic(array, MAX_SIZE);
 bool cols = areRowsMagic(array, MAX_SIZE, 0);
 bool diag = areDiagMagic(array, MAX_SIZE);

 if (rows && cols && diag)
 {
  return 1;
 }

 return 0;
}

void main()
{
 const unsigned int MAX_SIZE = 10;
 char charsData[MAX_SIZE][MAX_SIZE];
 int charsQuantity = 0;
 std::cin >> charsQuantity;

 fillArray(charsData, charsQuantity);
 bool magic = isMagic(charsData, charsQuantity);

 if (magic)
 {
  std::cout << "magic palindrome";
 }
 else
 {
  std::cout << "not magic palindrome";
 }
}