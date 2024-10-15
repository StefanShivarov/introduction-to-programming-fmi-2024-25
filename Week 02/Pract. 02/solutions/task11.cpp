#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int startingNumber = 1;
    int numberToPrint = startingNumber;

    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << numberToPrint << " ";
            if(j%2==0)
            numberToPrint+=2*(n-i)-1;
            else
            numberToPrint+=i*2+1;
        }
        cout << endl;
        startingNumber+=1;
        numberToPrint=startingNumber;
    }
}