#include <iostream>

void shell_sort(int *arr, int len);
void output_arr(int *arr, int len);

int main() {
    srand(time(nullptr));

    std::cout << "Input len of array: ";
    int len;
    std::cin >> len;

    int *arr = new int[len];
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % 201 - 100;
    }

    std::cout << "Before sort: ";
    output_arr(arr, len);
    shell_sort(arr, len);
    std::cout << "After sort: ";
    output_arr(arr, len);
    delete[] arr;

    return 0;
}

void shell_sort(int *arr, int len) {
    for (int step = len / 2; step > 0; step /= 2) {
        for (int i = 0; i < len; ++i) {
            for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step) {
                int temp = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = temp;
            }
        }
    }
}

void output_arr(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}