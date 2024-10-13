#include <iostream>

using namespace std;

int main() {
    unsigned int year = 0;

    cout << "Year: "; cin >> year;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        cout << "The year is leap" << endl;
    } else {
        cout << "The year is not leap" << endl;
    }

    return 0;
}