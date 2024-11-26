#include <iostream>

size_t createMask(size_t size);
size_t cutNum(size_t num, size_t quantity, size_t startPos);

int main()
{
	size_t num = 0;
	size_t startPos = 0;
	size_t quantity = 0;

	std::cin >> num >> startPos >> quantity;

	size_t	resultNumber = cutNum(num, quantity, startPos);

	std::cout << resultNumber;
}

size_t cutNum(size_t num, size_t quantity, size_t startPos)
{
	startPos++;
	size_t mask = createMask(quantity);
	
	size_t resNum = num >> startPos;
	size_t result = resNum & mask;

	return result;
}

size_t createMask(size_t size)
{
	size_t mask = 0;

	for (int i = 0; i < size; i++)
	{
		mask = mask | 1 << i;
	}

	return mask;
}