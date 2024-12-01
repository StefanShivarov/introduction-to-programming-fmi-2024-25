#include <iostream>

using namespace std;

const size_t MIN_LENGTH = 1, MAX_LENGTH = 10;

bool isInputDataValid(size_t length) {
	return(length >= MIN_LENGTH && length <= MAX_LENGTH);
}

void readArray(int* ptr, size_t length) {
	for (size_t i = 0; i < length; i++) {
		cin >> *ptr;
		ptr++;
	}
}

void findAddressOfLargestNum(int* ptrArr, size_t length, int*& ptrRes) {
	int maxNum = *ptrArr;

	for (size_t i = 0; i < length; i++) {
		if (*ptrArr > maxNum) {
			ptrRes = ptrArr;
		}
		ptrArr++;
	}

}

int main() {
	size_t length = 0;
	cout << "Enter array size: ";
	cin >> length;

	if (!isInputDataValid(length)) {
		cout << "Incorrect input data!" << endl;
		return -1;
	}

	int array[MAX_LENGTH] = {};
	int* ptrArr = array;

	cout << "Enter the elements of the array: ";
	readArray(ptrArr, length);

	int* ptrRes = ptrArr;

	findAddressOfLargestNum(ptrArr, length, ptrRes);
	cout << "The address of the largest number of the array is " << ptrRes << endl;
}