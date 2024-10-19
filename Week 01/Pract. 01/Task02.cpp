//
// Created by Niya Neykova on 11.10.24.
//

#include <iostream>
using namespace std;
int main() {
    int a,b,c,d,s=0;
    cin>>a>>b>>c>>d;
    if(a%2==0) {
        s+=a;
    }
    if(b%2==0) {
        s+=b;
    }
    if(c%2==0) {
        s+=c;
    }
    if(d%2==0) {
        s+=d;
    }
    cout<<s<<endl;

    return 0;
}