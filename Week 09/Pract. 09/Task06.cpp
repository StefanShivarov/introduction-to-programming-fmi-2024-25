#include <iostream>

using namespace std;

const size_t MAX_SIZE = 100;
const size_t ALPHABET_SIZE = 26;

char* deleteRepeatingLetters(char* str);

int main() {
    char str[MAX_SIZE];

    cout << "Enter a string: ";
    cin.getline(str, MAX_SIZE);

    cout << "Result: " << deleteRepeatingLetters(str) << endl;

    return 0;
}

char* deleteRepeatingLetters(char* str) {
    bool letterUsedFlags[ALPHABET_SIZE] = {0};

    int currentIdx = 0, lastLetterIdx = 0;

    while (str[currentIdx]) {
        int letterIdx = str[currentIdx] - 'a';

        if (!letterUsedFlags[letterIdx]) {
            letterUsedFlags[letterIdx] = true;
            str[lastLetterIdx++] = str[currentIdx];
        }

        ++currentIdx;
    }

    str[lastLetterIdx] = '\0';

    return str;
}