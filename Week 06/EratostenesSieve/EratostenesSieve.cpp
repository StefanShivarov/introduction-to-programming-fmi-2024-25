/*
* Task: 
*   Find out which natural numbers in the interval [0, n], n >= 0, are prime
* Approach:
*   Eratostenes's Sieve is an algorithm that finds the natural numbers in the interval [0, n]. Here's how it works:
*   If you have a prime number, then all numbers that are divisible by that number are, by definition, not prime.
*   If you order the natural numbers in a line by order, then each number divisible by i will be i hops over from the previous such number
*   Thus, you can use a for loop to mark every i-th number in an interval of [0, n] and mark it as prime
*   
*   
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 1001;

//initialise a bool array - first and second element are false (0 and 1 are not prime), the rest are true by default
void initArray(bool arr[], int size)
{
    if (size <= 0)
        return;

    if (size == 1)
    {
        arr[0] = false;
        return;
    }

    if (size == 2)
    {
        arr[0] = false;
        arr[1] = false;
        return;
    }

    for (int i = 2; i < size; i++)
    {
        arr[i] = true;
    }
}

//prints whether the numbers in the interval [0, size - 1] are prime
void printPrimes(bool arr[], int size)
{
    if (size <= 0)
        return;

    for (int i = 0; i < size; i++)
    {
        if (arr[i])
        {
            cout << i << " is prime" << endl;
        }
        else
        {
            cout << i << " is not prime" << endl;
        }
    }
}

//marks every numbers that's divisible by startingIndex - those are surely not prime
void removeNumbers(bool arr[], int size, int startingIndex)
{
    for (int j = startingIndex + startingIndex; j < size; j += startingIndex)
    {
        arr[j] = false;
    }
}

//loops until the size
void unoptimisedEratostenesSieve(bool arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i])
        {
            removeNumbers(arr, size, i);
        }
    }
}

//loops until the square root of size
void optimisedEratostenesSieve(bool arr[], int size)
{
    int sqrtOfSize = sqrt(size);
    for (int i = 0; i < sqrtOfSize; i++)
    {
        if (arr[i])
        {
            removeNumbers(arr, size, i);
        }
    }
}

//alternatively we can pass the end of the loop as an argument
void eratostenesSieveWithEnd(bool arr[], int size, int end)
{
    for (int i = 0; i < end; i++)
    {
        if (arr[i])
        {
            removeNumbers(arr, size, i);
        }
    }
}

int main()
{
    bool primes[MAX_SIZE]{ false, false };
    initArray(primes, MAX_SIZE);
    optimisedEratostenesSieve(primes, MAX_SIZE);
    printPrimes(primes, MAX_SIZE);
}
