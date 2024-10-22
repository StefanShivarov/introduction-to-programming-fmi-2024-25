#include <iostream>
#include <math.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int discriminant = 0;
	double x1 = 0;
	double x2 = 0;

	std::cout << "Please enter a, b and c: "; std::cin >> a >> b >> c;

	discriminant = b * b - 4 * a * c;

	if (discriminant < 0) {
		std::cout << "Roots are complex conjugate" << std::endl;
	} else if (!discriminant) {
		x1 = -b / 2 * a;
		std::cout << "x1 = " << x1 << std::endl;
		std::cout << "x2 = " << x1 << std::endl;
	} else {
		x1 = -b + sqrt(discriminant) / 2 * a;
		x2 = -b - sqrt(discriminant) / 2 * a;

		std::cout << "x1 = " << x1 << std::endl;
		std::cout << "x2 = " << x2 << std::endl;
	}

	return 0;
}