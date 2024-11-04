#include <iostream>

using namespace std;

void deposit(double& balance, double amount);
void withdraw(double& balance, double amount);
void printBalance(double balance);

int main() {
	double balance = 0.0;
	deposit(balance, 49.99);
	printBalance(balance);
	withdraw(balance, 55.50);
	printBalance(balance);
	withdraw(balance, 40);
	printBalance(balance);
}

void deposit(double& balance, double amount) {
	balance += amount;
}

void withdraw(double& balance, double amount) {
	if (balance > amount) {
		balance -= amount;
	}
	else {
		cout << "Not enough balance!" << endl;
	}
}

void printBalance(double balance) {
	cout << balance << endl;
}