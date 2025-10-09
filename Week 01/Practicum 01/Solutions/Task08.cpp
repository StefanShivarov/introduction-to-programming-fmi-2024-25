#include <iostream>

int main()
{
	float first_opearand = 0;
	unsigned char prompt_operator;
	float second_opearand = 0;

	std::cout << "Please enter first operand, operator and second operand: "; std::cin >> first_opearand >> prompt_operator >> second_opearand;

	if (prompt_operator == '+') {
		std::cout << first_opearand + second_opearand;
	}

	if (prompt_operator == '-') {
		std::cout << first_opearand - second_opearand;
	}

	if (prompt_operator == '*') {
		std::cout << first_opearand * second_opearand;
	}

	if (prompt_operator == '/' && second_opearand) {
		std::cout << first_opearand / second_opearand;
	} else if (prompt_operator == '/' && !second_opearand) {
		std::cout << "Error! You can't divide by 0!" << std::endl;
	}

	return 0;
}