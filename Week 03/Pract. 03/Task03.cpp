#include <iostream>

using namespace std;

int askUser(const int, const int);

int main() {
    int from = 0, to = 0;

    cout << "Enter interval [from, to]: ";
    cin >> from >> to;

    int result = askUser(from, to);
    cout << "Result: " << result << endl;
}

int askUser(const int from, const int to) {
    while (true) {
        int num = 0;
        cin >> num;

        if (num >= from && num <= to) {
            return num;
        }
    }
}