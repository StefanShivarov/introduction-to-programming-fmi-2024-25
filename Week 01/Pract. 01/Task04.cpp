//
// Created by Niya Neykova on 11.10.24.
//

#include <iostream>
using namespace std;
int main() {
    int a,b,x;
    cin>>a>>b>>x;
    if(x<a) {
        cout<<1<<endl;
    } else if(x==a) {
        cout<<2<<endl;
    } else if(x>a && x<b) {
        cout<<3<<endl;
    } else if(x==b) {
        cout<<4<<endl;
    } else if(x>b) {
        cout<<5<<endl;
    }

    return 0;
}