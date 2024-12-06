#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

char findLongestCommonPrefix(char arr1[], char arr2[], char arr3[], char result[]) {

    int i = 0;
    while (arr1[i] != '\0' && arr2[i] != '\0' && arr3[i] != '\0') {
        if (arr1[i] == arr2[i] && arr2[i] == arr3[i]) {
            result[i] = arr1[i];
        }
        else {
            break;
        }
        i++;
    }

    result[i] = '\0';
    cout << result;
    return 0;
}

int main() {
    char arr1[MAX_SIZE], arr2[MAX_SIZE], arr3[MAX_SIZE], result[MAX_SIZE];
    cin >> arr1;
    cin >> arr2;
    cin >> arr3;

    findLongestCommonPrefix(arr1, arr2, arr3, result);

    return 0;
}
