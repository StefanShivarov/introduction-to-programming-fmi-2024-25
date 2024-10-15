#include <iostream>

using namespace std;

int main() {
	int N = 0;
	int K = 0;
	int K_summable = 0;
	int counter = 0;
	int sum = 0;

	cout << "Please enter N and K, to get K numbers to N digits consequentially: ";
	cin >> N >> K;

	while (N) {
		counter = N;
		K_summable = K;

		while (counter) {
			sum += K_summable;
			K_summable *= 10;
			--counter;
		}

		--N;
	}

	cout << "Out: " << sum;

	return 0;
}