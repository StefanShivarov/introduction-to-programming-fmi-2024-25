#include <iostream>

bool isPrime (int n)
{
	if (n < 2) {
		std::cout << "Incorrect value, please provide valid data." << std::endl;
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

void main()
{
	int prompt_number = 0;

	std::cout << "Please enter a number you want to check for being prime: ";
	std::cin >> prompt_number;

	int result = isPrime(prompt_number);

	if (result)
	{
		std::cout << "Entered number is a prime number.";
	}
	else
	{
		std::cout << "Entered number is not a prime number.";
	}
	return;
}