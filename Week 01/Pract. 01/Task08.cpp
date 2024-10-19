//
// Created by Niya Neykova on 12.10.24.
//

#include <iostream>
using namespace std;
int main() {
    double a,b;
    char c;
    cin>>a>>c>>b;

    switch(c) {
        case '+':
            cout<<a+b<<endl;
            break;
        case '-':
            cout<<a-b<<endl;
            break;
        case '*':
            cout<<a*b<<endl;
            break;
        case '/':
            if(b!=0) {
                cout<<a/b<<endl;
            }else {
                cout<<"Error! You can't divide by 0!"<<endl;
            }
            break;
        default:
            cout<<"Error"<<endl;
    }

    return 0;
}