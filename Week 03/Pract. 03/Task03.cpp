#include <iostream>
using namespace std;

int askUser(const int from, const int to) {
    while (true) {
        int k;
        cin >> k;
        if (k >= from && k < to) {
            return k;
        }
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    int result = askUser(a, b);
    cout << result << endl;
    return 0;
}
