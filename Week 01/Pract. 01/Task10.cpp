//
// Created by Niya Neykova on 12.10.24.
//

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    double d=0,x1=0,x2=0;
    d=pow(b,2)-4*a*c;
    x1=(-b+sqrt(d))/(2*a);
    x2=(-b-sqrt(d))/(2*a);
    cout<<"x1="<<x1<<endl;
    cout<<"x2="<<x2<<endl;

    return 0;
}