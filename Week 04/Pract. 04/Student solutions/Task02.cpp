#include <iostream>

using namespace std;

void deposit(double& balance, double amount);
void withdraw(double& balance, double amount);

int main() {
    double balance = 0.0;
    deposit(balance, 49.99);
    std::cout << balance << std::endl;
    withdraw(balance, 55.50);
    std::cout << balance << std::endl;
    withdraw(balance, 40);
    std::cout << balance << std::endl;

    return 0;
}

void deposit(double& balance, double amount) {
    balance += amount;
}

void withdraw(double& balance, double amount) {
    if (balance < amount) {
        cout << "Not enough balance!" << endl;
        return;
    }

    balance -= amount;
}