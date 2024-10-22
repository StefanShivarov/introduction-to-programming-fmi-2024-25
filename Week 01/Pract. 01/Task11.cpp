#include <iostream>
#include <math.h>

int main()
{
	float first_number = 0;
	float second_number = 0;

	std::cout << "First number: "; std::cin >> first_number;
	std::cout << "Second number: "; std::cin>> second_number;

	first_number += second_number;
	second_number = first_number - second_number;
	first_number -= second_number;


	std::cout << "First number: "<< first_number << std::endl;
	std::cout << "Second number: " << second_number << std::endl;

	return 0;
}