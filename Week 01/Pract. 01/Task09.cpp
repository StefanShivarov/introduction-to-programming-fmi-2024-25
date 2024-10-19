//
// Created by Niya Neykova on 12.10.24.
//

#include <iostream>
using namespace std;
int main() {
    int y;
    cin >> y;
    if(y%400==0) {
        cout<<"Leap year"<<endl;
    } else {
        if(y%100!=0 && y%4==0) {
            cout<<"Leap year"<<endl;
        } else {
            cout<<"Not leap"<<endl;
        }
    }

    return 0;
}