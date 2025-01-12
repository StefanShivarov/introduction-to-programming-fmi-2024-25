#include <iostream>
using namespace std;

char* mySubstr(const char* str, size_t strLen, size_t startIndex, size_t len) {
    if (startIndex >= strLen) {
        return nullptr;
    }
    size_t endIndex = startIndex + len > strLen ? strLen : startIndex + len;
    size_t resultLength = endIndex - startIndex + 1; // +1 for null terminator

    char* result = new char[resultLength];
    for (size_t i = startIndex; i < endIndex; i++) {
        result[i - startIndex] = str[i];
    }
    result[resultLength - 1] = '\0';
    return result;
}

bool isWhitespace(char symbol) {
    return symbol == ' ' || symbol == '\t';
}

int main() {
    char input[1024];
    cin.getline(input, 1024);

    size_t maxStartIndex = 0, maxEndIndex = 1;
    size_t currentStartIndex = 0, currentEndIndex = 1;
    size_t currentAsciiSum = 0, maxAsciiSum = 0;
    size_t i = 0;
    while (input[i] != '\0') {
        if (isWhitespace(input[i])) {
            if (i > 0 && !isWhitespace(input[i - 1])) {
                // a word has just finished
                currentEndIndex = i;
                if (currentAsciiSum > maxAsciiSum) {
                    maxAsciiSum = currentAsciiSum;
                    maxStartIndex = currentStartIndex;
                    maxEndIndex = currentEndIndex;
                }
                currentAsciiSum = 0;
            }
            i++;
            continue;
        }
        currentAsciiSum += input[i];

        if (i > 0 && isWhitespace(input[i - 1])) {
            // a new word has started
            currentStartIndex = i;
        }
        i++;
    }

    // last word finished
    currentEndIndex = i;
    if (currentAsciiSum > maxAsciiSum) {
        maxAsciiSum = currentAsciiSum;
        maxStartIndex = currentStartIndex;
        maxEndIndex = currentEndIndex;
    }

    char* result = mySubstr(input, i, maxStartIndex, maxEndIndex - maxStartIndex);

    if (result != nullptr) {
        cout << "Word with the highest ASCII sum: " << result << endl;
        delete[] result;
    } else {
        cout << "Invalid input." << endl;
    }

}
