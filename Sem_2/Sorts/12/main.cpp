#include <iostream>

void bucket_sort(int *arr, int len);
void output_array(int *arr, int len);
int main() {
    srand(time(nullptr));

    std::cout << "Input len of array: ";
    int len;
    std::cin >> len;

    int *arr = new int[len];
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % 201 - 100;
    }

    output_array(arr, len);
    bucket_sort(arr, len);   
    output_array(arr, len);

    return 0;
}

void bucket_sort(int *arr, int len) {
    int max = arr[0], min = arr[0];
    for (int i = 0; i < len; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    if (min == max) {
        return;
    }

    for (int i = 0; i < len; ++i) {
        int ind = arr[i] * n / (max - min);
        buckets[ind][size[ind]] = arr[i];

}



void output_array(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}