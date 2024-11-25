#include <iostream>

using namespace std;

long myPow(int m);

long calculate(int n, int m);

int main() {
	int n = 0, m = 0;
	cout << "Enter n and m: ";
	cin >> n >> m;

	cout << "n * 2 ^ m = " << calculate(n, m);
}

long myPow(int m) {
	long pow2 = 1;

	for (int i = 1; i <= m;i++) {
		pow2 *= 2;
	}

	return pow2;
}

long calculate(int n, int m) {
	return(n * myPow(m));
}