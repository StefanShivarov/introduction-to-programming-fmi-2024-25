#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int g = 10;
    int c = 5;
    swap(c, g);
    cout << g << " " << c;
}
