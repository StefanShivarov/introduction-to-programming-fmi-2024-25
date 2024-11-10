#include <iostream>
using namespace std;

const size_t MAX_SIZE = 50, MIN_SIZE = 1;

bool isDataValid(size_t length);
void addElements(int arr[], size_t length);
double averageOfArray(const int(*array), int length);
int closestToAverage(int arr[], size_t length, double average);
double absFunction(double num);

int main() {
	size_t length = 0;
	cout << "Enter the number of values in the array(>=1 and <=50): ";
	cin >> length;

	int array[MAX_SIZE] = {};

	if (isDataValid(length)) {
		cout << "Enter the values of the array: ";
		addElements(array, length);

		double average = averageOfArray(array, length);
		cout << "Average: " << average << endl;
		cout << closestToAverage(array, length, average);
	}
	else {
		cout << "Incorrect input data!";
	}
 
 	return 0;
}

int closestToAverage(int arr[], size_t length, double average) {
	double difference = absFunction(average - arr[0]);
	int closestNum = arr[0];

	for (int j = 1;j < length;j++) {
		if (difference > absFunction(average - arr[j])) {
			difference = absFunction(average - arr[j]);
			closestNum = arr[j];
		}
	}

	return closestNum;
}

double absFunction(double num) {
	num = (num >= 0) ? num : -num;
	return num;
}

double averageOfArray(const int(*array), int length) {
	double sum = 0;

	for (int i = 0;i < length;i++) {
		sum += array[i];
	}

	return (sum / length);
}

bool isDataValid(size_t length) {
	if (length >= 1 && length <= 50) {
		return true;
	}
	else {
		return false;
	}
}

void addElements(int arr[], size_t length) {
	for (int i = 0;i < length;i++) {
		cin >> arr[i];
	}
}


