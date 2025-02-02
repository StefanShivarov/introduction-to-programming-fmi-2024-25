#include <iostream>
using namespace std;
 
size_t getTotalLength(const int* arr, size_t N, size_t subsetsCount) {
    size_t totalSize = 1;
    for (size_t mask = 1; mask <= subsetsCount; ++mask) {
        for (size_t i = 0; i < N; ++i) {
            if (mask & (1 << i)) totalSize++;
        }
        totalSize++;
    }
    return totalSize;
}
 
void fillSubset(const int* arr, size_t N, unsigned mask, int* result, size_t& index) {
    for (size_t i = 0; i < N; i++) {
        if (mask & (1 << i)) {
            result[index++] = arr[i];
        }
    }
}
 
void fillSubsetsArray(const int* arr, size_t N, int* result, size_t subsetsCount) {
    size_t index = 0;
    for (size_t mask = 1; mask <= subsetsCount; mask++) {
        fillSubset(arr, N, mask, result, index);
        result[index++] = 0;
    }
    result[index++] = 0;
}
 
int* findSets(const int arr[], size_t N) {
    if (N == 0) {
        return nullptr;
    }
 
    size_t subsetsCount = (1 << N) - 1;
    size_t totalSize = getTotalLength(arr, N, subsetsCount);
 
    int* result = new int[totalSize];
    fillSubsetsArray(arr, N, result, subsetsCount);
    return result;
}
 
void printArray(const int* arr) {
    if (!arr) return;
    size_t index = 0;
    while (true) {
        std::cout << arr[index] << " ";
        if (index > 0 && arr[index] == 0 && arr[index - 1] == 0) {
            break;
        }
        index++;
    }
}
 
int main() {
    int N;
    cin >> N;
    int* inputArr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> inputArr[i];
    }
 
    int* result = findSets(inputArr, N);
    printArray(result);
 
    delete[] result;
    return 0;
}
