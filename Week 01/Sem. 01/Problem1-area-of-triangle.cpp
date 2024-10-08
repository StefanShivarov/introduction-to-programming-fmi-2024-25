/*
* Task:
*	Input: 3 numbers representing the lengths of the sides of a triangle
*	Output: The surface area of the triangle
* Approach:
*	Heron's formula: sqrt(p*(p-a)*(p-b)*(p-c)) where p is the perimeter halved and a, b, and c are the sides of the triangle
*/

//standard input and output library & standard namespace - allow the use of cout, cin, and endl
#include <iostream>
using namespace std;


int main()
{
	//read the three sides from the standard input (keyboard)
	double a, b, c;
	cout << "Please enter the lengths of the three sides of your triangle: ";
	cin >> a >> b >> c;

	//calculate the half-perimeter p
	double p = (a + b + c) / 2;

	//calculate the product of p, p-a, p-b and p-c
	double middleProduct = p * (p - a) * (p - b) * (p - c);

	//calculate the end result - square root of middleProduct
	double area = sqrt(middleProduct);

	//print the result to the standart output - the terminal
	cout << "The surface area of your triangle is " << area << endl;


	return 0;
}
