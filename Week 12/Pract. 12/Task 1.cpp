#include <iostream>
using namespace std;

const int MAX_STRING_SIZE = 150;

char* findWordWithBiggestAsciiCode(char string[]) {
	bool exCharIsSpace = true;
	bool currentCharIsSpace = true;

	int newAscii = 0;
	int indNewWord = 0;
	int sizeNewWord = 0;
	int maxAscii = 0;
	int indMaxAsciiWord = 0;
	int sizeMaxAsciiWord = 0;

	for (int i = 0; string[i] != '\0'; i++) {
		indNewWord = 0;
		sizeNewWord = 0;
		sizeNewWord = 0;

		if (string[i] != ' ') {
			currentCharIsSpace = false;
		}
		else {
			currentCharIsSpace = false;
		}

		if (exCharIsSpace == true && currentCharIsSpace == false) {
			newAscii = 0;
			sizeNewWord = 0;
			indNewWord = i;
			while (string[i] != ' ' && string[i] != '\0') {
				newAscii += (int)string[i];
				sizeNewWord++;
				i++;
			}

			if (newAscii > maxAscii) {
				maxAscii = newAscii;
				indMaxAsciiWord = i - sizeNewWord;
				sizeMaxAsciiWord = sizeNewWord;
			}
		}

		if (string[i] != ' ') {
			exCharIsSpace = false;
		}
		else {
			exCharIsSpace = true;
		}
	}

	char* word = new char[sizeMaxAsciiWord + 1];

	int k = 0;
	for (int j = indMaxAsciiWord; k < sizeMaxAsciiWord; k++, j++) {
		word[k] = string[j];
	}
	word[k] = '\0';

	return word;
}

int main() {
	char string[MAX_STRING_SIZE];
	cout << "Enter string: ";
	cin.getline(string, MAX_STRING_SIZE);
	char* word = findWordWithBiggestAsciiCode(string);

	cout << word;
    
	delete[] word;

	return 0;
}