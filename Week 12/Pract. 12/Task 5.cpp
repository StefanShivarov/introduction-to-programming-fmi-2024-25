#include <iostream>
using namespace std;

const size_t MAX_SIZE = 100;

int myStrLen(char str[]) {
	int len = 0;
	for (size_t i = 0; str[i] != '\0'; i++) {
		len++;
	}
	return len;
}

char* censoredString(char string[], char censors[]) {
	int length = myStrLen(string) + 1;
	char* str = new char[length];

	for (int i = 0;i < length; i++) {
		str[i] = string[i];
	}

	int i = 0;
	for (i; str[i] != '\0'; i++) {
		for (int k = 0; censors[k] != '\0'; k++) {
			if (str[i] == censors[k]) {
				str[i] = '*';
				break;
			}
		}
	}

	return str;
}

int main() {
	char string[MAX_SIZE];
	cout << "Enter string: ";
	cin.getline(string, MAX_SIZE);

	char censors[MAX_SIZE];
	cout << "Enter another string: ";
	cin.getline(censors, MAX_SIZE);

	char* result = censoredString(string, censors);
	cout << result;


	delete[] result;
	return 0;
}