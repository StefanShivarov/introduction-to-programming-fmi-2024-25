#include <iostream>

void swap(size_t *pNum, size_t *pSecNum);

int main()
{
	size_t first = 1;
	size_t second = 3;
	size_t *pFirst = &first;
	size_t *pSecond = &second;

	swap(pFirst, pSecond);

	std::cout << first << std::endl;
	std::cout << second;
}

void swap(size_t *pNum, size_t *pSecNum)
{
	*pNum ^= *pSecNum;
	*pSecNum ^= *pNum;
	*pNum ^= *pSecNum;
}