#include <iostream>
using namespace std;

int main()
{
    int year;
    cin >> year;
    bool isLeap = false;

    if(year%400 == 0)
    isLeap=true;
    else if(year%100==0)
    isLeap = false;
    else if(year%4==0)
    isLeap=true;

    if(isLeap)
    cout << "Leap year";
    else
    cout << "Not Leap";
    return 0;
}