#include <iostream>
using namespace std;

void swap(int* &ptr1, int* &ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;

    swap(num1, num2);

    cout << num1 << " " << num2 << '\n';
}