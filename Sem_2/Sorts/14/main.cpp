#include <iostream>

void quick_sort(int *arr, int l, int r);
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

    output_arr(arr, len);
    quick_sort(arr, 0, len - 1);
    output_arr(arr, len);

    delete[] arr;

    return 0;
}

int partition(int *arr, int l, int r) {
    int v = arr[(l + r) / 2];
    int i = l, j = r;

    while (i <= j) {
        while (arr[i] < v) {
            ++i;
        }

        while (arr[j] > v) {
            --j;
        }

        if (i >= j) {
            break;
        }

        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;

        ++i;
        --j;
    }

    return j;
}

void quick_sort(int *arr, int l, int r) {
    if (l < r) {
        int q = partition(arr, l, r);
        quick_sort(arr, l, q);
        quick_sort(arr, q + 1, r);
    }
}

void output_arr(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}