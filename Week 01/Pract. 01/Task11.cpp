//
// Created by Niya Neykova on 12.10.24.
//

#include <iostream>
using namespace std;
int main() {
    double a,b;
    cout<<"First number: ";
    cin>>a;
    cout<<"Second number: ";
    cin>>b;
    a=a*b;
    b=a/b;
    a=a/b;
    cout<<"First number: "<<a<<endl;
    cout<<"Second number: "<<b<<endl;

    return 0;
}