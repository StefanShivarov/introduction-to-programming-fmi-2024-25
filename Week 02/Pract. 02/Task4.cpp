#include <iostream>

using namespace std;

int main() {
    unsigned int countOfPositives = 0, sumOfPositives = 0;

    while (countOfPositives != 5) {
        int num = 0;
        cin >> num;

        if (num > 0) { 
            ++countOfPositives; 
            sumOfPositives += num;
        }
    }

    cout << "The sum is: " << sumOfPositives << endl;

    return 0;
}