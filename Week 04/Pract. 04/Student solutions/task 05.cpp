#include <iostream>
using namespace std;

double f(double& a, int b)
{
    return a / b;
}
int main()
{
    int n, chislo;
    double srednoaritm;
    cin >> n;
    if (n > 1 && n < 50)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> chislo;
            srednoaritm = srednoaritm + chislo;
        }

        cout << "Average: " << f(srednoaritm, n);


    }
    else { cout << "error"; }

}