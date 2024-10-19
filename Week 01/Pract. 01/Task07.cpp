//
// Created by Niya Neykova on 12.10.24.
//

#include <iostream>
using namespace std;
int main() {
    double r, x, y;
    cin >> r >> x >> y;
    if(pow(x,2)+pow(y,2) == pow(r,2)) {
        cout << "On the circle" << endl;
    } else if(pow(x,2)+pow(y,2) > pow(r,2)) {
        cout << "Out of the circle" << endl;
    } else if(pow(x,2)+pow(y,2) < pow(r,2)) {
        cout << "In the circle" << endl;
    }

    return 0;
}