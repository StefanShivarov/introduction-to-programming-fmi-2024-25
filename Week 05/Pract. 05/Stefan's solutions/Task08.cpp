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

void intersect(int* first, unsigned firstLength,
               int* second, unsigned secondLength,
               int* intersection, unsigned& intersectionLength) {

    int smallerLength = firstLength < secondLength ? firstLength : secondLength;

    for (int i = 0; i < smallerLength; i++) {
        if (count(second, secondLength, first[i]) && count(intersection, intersectionLength, first[i]) == 0) {
            intersection[intersectionLength++] = first[i];
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

    int intersection[MAX_SIZE];
    unsigned intersectionSize = 0;
    
    intersect(first, n, second, m, intersection, intersectionSize);

    printArray(intersection, intersectionSize);
}
