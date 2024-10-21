#include <iostream>
<<<<<<< Updated upstream

using namespace std;

int main() {
    int index = 0;
    cin >> index;

    int current = 1;
    int previous = 0;
    for (int i = 2; i < index; i++) {
        int next = current + previous;
        previous = current;
        current = next;
    }


    if (index == 1) {
        cout << 0;
    } else {
        cout << current;
    }

    return 0;
}
=======
using namespace std;

int main() {
    int n = 0, k = 1, a, num = 0;
    cin >> a;
    if (a == 1) {
        cout << 0;
    } else if (a == 2) {
        cout << 1;
    } else {
        for (int i = 2; i < a; i++) {
            num = n + k;
            n = k;
            k = num;
        }
        cout << num;
    }

    return 0;
}
>>>>>>> Stashed changes
