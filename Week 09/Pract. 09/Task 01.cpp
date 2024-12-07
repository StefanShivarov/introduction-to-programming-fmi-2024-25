#include <iostream>
using namespace std;

int myStrlen(char* arr) {
	int length = 0;

	while (*arr != '\0') {
		length++;
		arr++;
	}

	return length;
}

void myStrcpy(char* src, char* dest) {
	while (*src != '\0') {
		*dest = *src;

		dest++;
		src++;
	}

	*dest = '\0';
}

void myStrcat(char* src, char* dest) {
	int srcLen = myStrlen(src);

	int i = srcLen, j = 0;
	for (i, j; src[j] != '\0'; i++, j++) {
		dest[i] = src[j];
	}

	dest[i] = '\0';
}

int main() {
	char src[] = "Hello, World!";
	char dest[100] = {};

	cout << myStrlen(src) << endl;

	myStrcpy(src, dest);
	for (int i = 0; dest[i] != '\0'; i++) {
		cout << dest[i];
	}

	cout << endl;

	myStrcat(src, dest);
	for (int i = 0; dest[i] != '\0'; i++) {
		cout << dest[i];
	}

	cout << endl;

    return 0;
}