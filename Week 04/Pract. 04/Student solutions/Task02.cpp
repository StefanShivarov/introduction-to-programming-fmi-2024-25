#include <iostream>

using namespace std;

void deposit(double&, double);
void withdraw(double&, double);

int main() {
    double balance = 0.0;
    
    deposit(balance, 49.99);
    cout << balance << endl;
    withdraw(balance, 55.50);
    cout << balance << endl;
    withdraw(balance, 40);
    cout << balance << endl;

    return 0;
}

void deposit(double& balance, double amount) {
    balance += amount;
}

void withdraw(double& balance, double amount) {
    if (balance - amount < 0) {
        cout << "Not enough balance!" << endl;
    } else {
        balance -= amount;
    }
}