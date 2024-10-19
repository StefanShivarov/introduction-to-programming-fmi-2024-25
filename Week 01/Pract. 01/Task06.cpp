//
// Created by Niya Neykova on 11.10.24.
//

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    switch (n) {
        case 1:
            cout<<"Monday"<<endl;
            break;
        case 2:
            cout<<"Tuesday"<<endl;
            break;
        case 3:
            cout<<"Wednesday"<<endl;
            break;
        case 4:
            cout<<"Thursday"<<endl;
            break;
        case 5:
            cout<<"Friday"<<endl;
            break;
        case 6:
            cout<<"Saturday"<<endl;
            break;
        case 7:
            cout<<"Sunday"<<endl;
            break;
        default:
            cout<<"Error. Number must be between 1 and 7"<<endl;
    }

    return 0;
}