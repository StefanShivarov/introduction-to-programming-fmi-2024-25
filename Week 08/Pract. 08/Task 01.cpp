#include <iostream>

using namespace std;

void changePtrAddress(int*& ptr) {
	ptr = nullptr;
}

int main() {
	int num = 0;
	int* ptr = &num;
	cout << ptr << endl;

	changePtrAddress(ptr);
	cout << ptr << endl;
}