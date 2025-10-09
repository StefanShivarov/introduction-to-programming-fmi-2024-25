#include <iostream>

int main()
{
	int r = 0;
	int x = 0;
	int y = 0;

	std::cout << "Please enter radius, x and y of a point: "; std::cin >> r >> x >> y;

	if (x * x + y * y < r * r) {
		std::cout << "In the circle";
	} else if (x * x + y * y == r * r) {
		std::cout << "On the circle";
	} else {
		std::cout << "Out of the circle";
	}

	return 0;
}