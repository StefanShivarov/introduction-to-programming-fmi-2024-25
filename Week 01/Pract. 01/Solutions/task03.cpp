#include <iostream>
using namespace std;

int main()
{
    int seconds;
    cin >> seconds;
    int days = seconds / 60 / 60 / 24;
    seconds %= (60 * 60 * 24);
    int hours = seconds / 60 / 60;
    seconds %= (60 * 60);
    int minutes = seconds / 60;
    seconds %= (60);
    cout << days <<" days, " << hours << "hours, " << minutes << "minutes " << seconds << "and 48 seconds";
    return 0;
}