#include <iostream>

void changeBit(size_t &num, size_t pos);

int main()
{
	size_t num = 0;
	size_t pos = 0;

	std::cin >> num >> pos;

	changeBit(num, pos);

	std::cout << num;
}

void changeBit(size_t &num, size_t pos)
{
	if (num & (1 << pos))
	{
		num = num & ~(1 << pos);
	}
	else
	{
		num = num & (1 << pos);
	}
}