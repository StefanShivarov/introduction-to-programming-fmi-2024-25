#include <iostream>

int main()
{
	int prompt_number = 0;
	int final_sum = 0;
	int final_product = 0;
	float final_average = 0;
	int digit_1 = 0;
	int digit_2 = 0;
	int digit_3 = 0;
	int digit_4 = 0;

	std::cout << "Please enter 4-digit numbers "; std::cin >> prompt_number;

	digit_4 = prompt_number % 10;
	prompt_number /= 10;
	digit_3 = prompt_number % 10;
	prompt_number /= 10;
	digit_2 = prompt_number % 10;
	prompt_number /= 10;
	digit_1 = prompt_number;

	final_sum = digit_1 + digit_2 + digit_3 + digit_4;
	final_product = digit_1 * digit_2 * digit_3 * digit_4;
	final_average = final_sum / 4.0;

	std::cout << "sum=" << final_sum << " p=" << final_product << " avr=" << final_average << std::endl;

	return 0;
}