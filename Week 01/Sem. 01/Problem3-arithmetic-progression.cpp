/*
* Task:
*	Input: two natural numbers n and d
*	Output: the sum of all natural numbers which are smaller than or equal to n and which are divisible by d
* Approach:
*	n/d gives the number of numbers that satisfy the above conditions
*	d is always the first number. The next is 2*d, the one after - 3*d and so on...
*	Therefore, the sum is equal to d * (1 + 2 + ... + n/d)
*	And the formula for the sum of the first k natural numbers is (k * (k + 1)) / 2
*	Therefore, if n/d = k, then the result is d * (k * (k + 1)) / 2
*/

#include <iostream>
using namespace std;


int main()
{
	int n, d;
	cout << "Enter your n and your d: ";
	cin >> n >> d;

	int k = n / d;

	int sum = d * (k * (k + 1) / 2);

	cout << "Your sum is " << sum << endl;



	return 0;
}
