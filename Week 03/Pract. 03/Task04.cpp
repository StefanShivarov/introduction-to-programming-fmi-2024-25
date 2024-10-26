#include <iostream>

bool ifTriangle(const int first_side, const int second_side, const int third_side)
{

	if (first_side > 0 && second_side > 0 && third_side > 0 )
	{
		if (first_side + second_side < third_side )
		{
			return 0;
		}

		if (first_side + third_side < second_side )
		{
			return 0;
		}

		if (third_side + second_side < first_side )
		{
			return 0;
		}
		
		return 1;
	}
	else
	{
		return 0;
	}
}

void buildMatrix(const int CYCLES)
{
	int increment = CYCLES;
	int side_a = 0;
	int side_b = 0;
	int side_c = 0;

	std::cout << "Now the cycle will start, please enter three numbers per row: ";

	while (increment)
	{
		std::cin >> side_a >> side_b >> side_c;

		bool check_sides = ifTriangle(side_a, side_b, side_c);

		if (check_sides)
		{
			std::cout << side_a << " " << side_b << " " << side_c << std::endl;
		}

		std::cout << std::endl;
		--increment;
	}
	return;
}

void main()
{
	int matrix_rows = 0;
	
	std::cout << "Please enter a number to start building a matrix with fixed coulumn length of 3: ";
	std::cin >> matrix_rows;

	buildMatrix(matrix_rows);

	return;
}