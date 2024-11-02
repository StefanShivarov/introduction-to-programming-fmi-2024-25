#include <iostream>

void deposit(double& balance, double amount)
{
	balance += amount;
}

void withdraw(double& balance, double amount)
{
	if (balance - amount < 1)
	{
		std::cout << "Not enough balance!" << std::endl;
	}
	else
	{
		balance -= amount;
	}
}

void main()
{
	double balance = 0.0;
	deposit(balance, 49.99);
	std::cout << balance << std::endl;
	withdraw(balance, 55.50);
	std::cout << balance << std::endl;
	withdraw(balance, 40);
	std::cout << balance << std::endl;
}