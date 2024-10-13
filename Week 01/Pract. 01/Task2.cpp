#include <iostream>

using namespace std;

int main() {
   unsigned int a = 0, b = 0, c = 0, d = 0, sum = 0;

   cout << "Numbers: ";
   cin >> a >> b >> c >> d;

   if (a % 2 == 0) { sum += a; }
   if (b % 2 == 0) { sum += b; }
   if (c % 2 == 0) { sum += c; }
   if (d % 2 == 0) { sum += d; }

   cout << "The sum is: " << sum << endl;

   return 0;
}