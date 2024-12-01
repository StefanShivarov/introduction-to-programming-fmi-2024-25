#include <iostream>

void nulifyPtr(size_t *&rPtr);

int main()
{
	size_t value = 1;
	size_t *ptr = &value;
	std::cout << ptr << std::endl;

	nulifyPtr(ptr);

	std::cout << ptr;
}

void nulifyPtr(size_t *&rPtr)
{
	rPtr = nullptr;
}