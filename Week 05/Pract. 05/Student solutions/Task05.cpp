#include <iostream>

double absolute(double value)
{
 if (value < 0) {
  return -value;
 }

 return value;
}

double returnAverage(int array[], const int SIZE)
{ 
 double result = 0;

 for (int i = 0; i < SIZE; ++i)
 {
  result += array[i];
 }

 return result /= SIZE;
}

void fillArray(int* array, const int SIZE)
{
 for (int i = 0; i < SIZE; ++i)
 {
  std::cin >> array[i];
 }
}


int findClosest(int* array, const int SIZE, const double AVERAGE)
{
 double diff = 0;
 int closest = 0;

 for (int i = 0; i < SIZE; ++i)
 {
  double diffAbsolute = absolute(array[i] - AVERAGE);
  
  if ( !(diff) || diff > diffAbsolute)
  {
   diff = diffAbsolute;
   closest = array[i];
  }
 }

 return closest;
}

void main()
{
 int numbersQuantity = 0;
 const unsigned int MAX_SIZE = 15;
 int numbers[MAX_SIZE];

 std::cin >> numbersQuantity;
 fillArray(numbers, numbersQuantity);

 double average = returnAverage(numbers, numbersQuantity);
 int closest = findClosest(numbers, numbersQuantity, average);
 std::cout << "Average: " << average << "\n" << closest;

}