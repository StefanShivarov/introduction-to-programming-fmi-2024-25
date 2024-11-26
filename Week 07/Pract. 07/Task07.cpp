#include <iostream>

bool returnBit (size_t num, size_t pos);

int main ()
{
	size_t num = 0;
	size_t pos = 0;

	std::cout << "Number: ";
	std::cin >> num;
	std::cout << "Position: ";
	std::cin >> pos;

	bool bit = returnBit(num, pos);

	bit ? std::cout << "1" : std::cout << "0";
}

bool returnBit (size_t num, size_t pos)
{
	return num & (1 << pos) ? 1 : 0;
}