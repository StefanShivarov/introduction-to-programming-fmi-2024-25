#include <iostream>

using namespace std;

int main() {
    unsigned int count = 0;
    cin >> count;

    int sum = 0;
    for (int i = 0; i < count; i++) {
        int num = 0;
        cin >> num;
        sum += num;
    }
   
    cout << sum << endl;
}
