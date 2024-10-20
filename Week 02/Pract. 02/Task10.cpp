#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num = 0;

    cout << "Num: "; 
    cin >> num;

    while (true) {
        int base = log2(num);
        num = num - pow(2, base);

        if (num > 0) {
            cout << "2^" << base << " + ";
        } else {
            cout << "2^" << base << endl;
            break;
        }
    }

    return 0;
}