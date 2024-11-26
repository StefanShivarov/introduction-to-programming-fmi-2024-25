#include <iostream>

size_t returnMultPow (size_t num, size_t pow);

int main ()
{
	size_t num = 0;
	size_t pow = 0;

	std::cin >> num >> pow;

	size_t result = returnMultPow(num, pow);

	std::cout << result;
}

size_t returnMultPow (size_t num, size_t pow)
{
	return num << pow;
}