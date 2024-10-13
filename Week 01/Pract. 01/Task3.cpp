#include <iostream>

using namespace std;

const unsigned int SECONDS_IN_DAY = 86400;
const unsigned int SECONDS_IN_HOUR = 3600;
const unsigned int SECONDS_IN_MINUTE = 60;

int main() {
    unsigned int totalSeconds = 0;

    cout << "Seconds: "; cin >> totalSeconds;

    unsigned int days = totalSeconds / SECONDS_IN_DAY;
    unsigned int remainingSeconds = totalSeconds % SECONDS_IN_DAY;

    unsigned int hours = remainingSeconds / SECONDS_IN_HOUR;
    remainingSeconds %= SECONDS_IN_HOUR;

    unsigned int minutes = remainingSeconds / SECONDS_IN_MINUTE;
    remainingSeconds %= SECONDS_IN_MINUTE;

    cout << days << " days, " 
        << hours << " hours, " 
        << minutes << " minutes and " 
        << remainingSeconds << " seconds" << endl;

    return 0;
}