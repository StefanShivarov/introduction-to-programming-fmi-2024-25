#include <iostream>

using namespace std;

void printArray(int* ptr, size_t length) {
	for (size_t i = 0; i < length; i++) {
		cout << *ptr << " ";
		ptr++;
	}
}

int main() {
	const size_t length = 10;
	int array[length] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr = array;

	printArray(ptr, length);
}