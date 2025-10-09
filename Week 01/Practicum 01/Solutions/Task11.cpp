#include <iostream>
#include <math.h>

int main()
{
	double firstNumber = 0;
	double secondNumber = 0;

	std::cout << "First number: "; std::cin >> firstNumber;
	std::cout << "Second number: "; std::cin>> secondNumber;

	firstNumber += secondNumber;
	secondNumber = firstNumber - secondNumber;
	firstNumber -= secondNumber;

	std::cout << "First number: "<< firstNumber << std::endl;
	std::cout << "Second number: " << secondNumber << std::endl;

	return 0;
}