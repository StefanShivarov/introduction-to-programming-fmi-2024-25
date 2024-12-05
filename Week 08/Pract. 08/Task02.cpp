#include <iostream>

using namespace std;

void swap(int* a, int* b);

int main() {
    int num1 = 10, num2 = 20;
    
    cout << "Before: " << "num1 = " << num1 << ", num2 = " << num2 << endl;

    swap(&num1, &num2);

    cout << "After: " << "num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}

void swap(int* a, int* b) {
   if (a != nullptr && b != nullptr) {
       int temp = *a;
       *a = *b;
       *b = temp;
   }
}