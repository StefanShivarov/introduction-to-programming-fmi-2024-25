#include <iostream>

using namespace std;

int main() {
   int a = 0, b = 0;

   cout << "Dividend: "; cin >> a;
   cout << "Divisor: "; cin >> b;

   cout << "The quotient of the division is: " << a / b << endl;
   cout << "The remainder of the division is: " << a % b << endl;

   return 0;
}