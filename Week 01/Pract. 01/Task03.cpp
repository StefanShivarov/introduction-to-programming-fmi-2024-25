#include <iostream>

int main()
{
	int seconds = 0;
	int days = 0;
	int hours = 0;
	int minutes = 0;
	const int TIME_RATIO = 60;
	const int DAY_RATIO = 24;

	std::cout << "Please enter seconds: "; std::cin >> seconds;

	days = seconds / (TIME_RATIO * TIME_RATIO * DAY_RATIO);
	seconds %= (TIME_RATIO * TIME_RATIO * DAY_RATIO);
	hours = seconds / (TIME_RATIO * TIME_RATIO);
	seconds %= (TIME_RATIO * TIME_RATIO);
	minutes = seconds / TIME_RATIO;
	seconds %= TIME_RATIO;

	std::cout << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";

	return 0;
}