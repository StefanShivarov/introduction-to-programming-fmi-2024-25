//
// Created by Niya Neykova on 11.10.24.
//

#include <iostream>
using namespace std;
int main() {
    int number;
    double a=0,b=0,c=0,d=0;
    cin >> number;
    a = number%10; //2
    number=number/10;  //143
    b=number%10;    //3
    number=number/10;   //14
    c=number%10; //4
    d=number/10; //1

    cout<<"sum="<<a+b+c+d<<" p="<<a*b*c*d<<" avr="<<(a+b+c+d)/4<<endl;

    return 0;
}
