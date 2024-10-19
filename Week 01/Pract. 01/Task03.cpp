//
// Created by Niya Neykova on 11.10.24.
//

#include <iostream>
using namespace std;
int main() {
    int a,s=0,m=0,h=0;
    cout<<"Seconds: ";
    cin>>a;

    s=a%60;
    a=a/60;
    m=a%60;
    a=a/60;
    h=a%24;
    a=a/24;
    cout<<a<<" days, "<<h<<" hours, "<<m<<" minutes and "<<s<<" seconds"<<endl;

    return 0;
}