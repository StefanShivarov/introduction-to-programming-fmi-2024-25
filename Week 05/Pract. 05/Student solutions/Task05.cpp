#include <iostream>

using namespace std;

const size_t MAX_SIZE = 50;

void fill_arr(int* arr, size_t size);
double arr_average(const int* arr, size_t size);
int closest_to_number(const int* arr, size_t size, double number);
double abs_difference(int a, double b);

int main() {
    int arr[MAX_SIZE];

    size_t size;
    cin >> size;

    fill_arr(arr, size);

    double average = arr_average(arr, size);

    cout << "Average: " << average << endl;
    cout << closest_to_number(arr, size, average);

    return 0;
}

void fill_arr(int* arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

double arr_average(const int* arr, const size_t size) {
    int sum = 0;

    for (size_t i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / (double) size;
}

int closest_to_number(const int* arr, const size_t size, const double number) {
    int closest = arr[0];
    double difference = abs_difference(arr[0], number);

    for (size_t i = 1; i < size; i++) {
        if (difference > abs_difference(arr[i], number)) {
            difference = abs_difference(arr[i], number);
            closest = arr[i];
        }
    }

    return closest;
}

double abs_difference(const int a, const double b) {
    return (a > b) ? a - b : b - a;
}