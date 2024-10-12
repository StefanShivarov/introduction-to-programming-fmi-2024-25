#include <iostream>

int main()
{
	int dividend = 0;
	int divisor = 0;

	std::cout << "Please enter two numbers: "; std::cin >> dividend >> divisor;

	std::cout << "The quotient of the division is : " << dividend / divisor << std::endl;

	if (dividend % divisor)
	{
		std::cout << "The remainder of the division is : " << dividend % divisor << std::endl;
	}

	return 0;
}