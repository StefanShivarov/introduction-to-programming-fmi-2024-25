#include <iostream>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;

	std::cout << "a: " << a << "\nb: " << b;
}

void main()
{
	int promptNumberFirst = 0;
	int promptNumberSecond = 0;

	std::cout << "Enter a: ";
	std::cin >> promptNumberFirst;
	std::cout << "Enter b: ";
	std::cin >> promptNumberSecond;

	swap(promptNumberFirst, promptNumberSecond);
}