#include <iostream>
using namespace std;

void getLongestCommonPrefix(const char* first, const char* second, const char* third, char* result) {
    int index = 0;
    while (first[index] != '\0' && second[index] != '\0' && third[index] != '\0') {
        if (first[index] == second[index] && second[index] == third[index]) {
            result[index] = first[index];
        } else {
            break;
        }
        index++;
    }
    result[index] = '\0';
}

int main() {
    char first[50];
    cin >> first;
    char second[50];
    cin >> second;
    char third[50];
    cin >> third;

    char prefix[50];
    getLongestCommonPrefix(first, second, third, prefix);
    cout << prefix;
}