#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const unsigned MAX_SIZE = 50;

void readArray(int* arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(const int* arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

unsigned count(int* arr, unsigned size, int value) {
    unsigned counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            counter++;
        }
    }
    return counter;
}

void unionize(int* first, unsigned firstLength,
               int* second, unsigned secondLength,
               int* unionArr, unsigned& unionLength) {

    for (int i = 0; i < firstLength; i++) {
        unionArr[unionLength++] = first[i];
    }

    for (int i = 0; i < secondLength; i++) {
        if (count(first, firstLength, second[i]) == 0) {
            unionArr[unionLength++] = second[i];
        }
    }
}

int main() {
    unsigned n;
    cin >> n;

    int first[MAX_SIZE];
    readArray(first, n);

    unsigned m;
    cin >> m;

    int second[MAX_SIZE];
    readArray(second, m);

    int unionArr[MAX_SIZE * 2];
    unsigned unionSize = 0;
    
    unionize(first, n, second, m, unionArr, unionSize);

    printArray(unionArr, unionSize);
}
