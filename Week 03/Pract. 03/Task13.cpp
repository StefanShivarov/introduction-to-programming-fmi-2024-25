#include <iostream>

bool isPrime (int n)
{
	if (n < 2)
	{
		return false;
	}

	int increment = n - 1;

	while (increment)
	{
		if ( !(n % increment) && increment != 1 )
		{
			return false;
		}

		--increment;
	}

	return true;
}

int sumPrimes(const int NUMBER)
{
	int cycle_number = NUMBER;
	int final_sum = 0;
	int increment = 0;

	while (increment <= NUMBER)
	{
		bool check_prime = isPrime(increment);
		
		if (check_prime)
		{
			final_sum += increment;
		}

		++increment;
	}

	return	final_sum;
}

void main()
{
	int prompt_number = 0;

	std::cout << "Please enter a number and get a sum of primes before it: ";
	std::cin >> prompt_number;

	int result = sumPrimes(prompt_number);

	std::cout << "Sum of prime numbers before " << prompt_number << " is: " << result;

	return;
}