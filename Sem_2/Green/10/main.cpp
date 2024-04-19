#include <iostream>

void init_arr(int *arr, int size);
void print_arr(int *arr, int size);
void delete_arr(int *arr);
void delete_by_index(int **arr, int *size, int index);
void add_by_index(int **arr, int *size, int index, int count);

int main() {
    srand(time(nullptr));

    int size = rand() % 10 + 1;
    int *arr = (int *) calloc(size, sizeof(int));
    init_arr(arr, size);

    print_arr(arr, size);

    std::cout << std::endl << "Enter index to delete: ";
    int index;
    std::cin >> index;
    delete_by_index(&arr, &size, index);

    print_arr(arr, size);

    std::cout << std::endl << "Enter index to insert: ";
    std::cin >> index;
    std::cout << "Enter count: ";
    int count;
    std::cin >> count;
    add_by_index(&arr, &size, index, count);

    print_arr(arr, size);

    delete_arr(arr);

    return 0;
}

void init_arr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10 + 1;
    }
}

void print_arr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void delete_arr(int *arr) {
    free(arr);
}

void delete_by_index(int **arr, int *size, int index) {
    int *new_arr = (int *) realloc(*arr, *size * sizeof(int));

    for (int i = index; i < *size - 1; i++) {
        new_arr[i] = new_arr[i + 1];
    }

    --(*size);
    new_arr = (int *) realloc(new_arr, *size * sizeof(int));

    *arr = new_arr;
}

void add_by_index(int **arr, int *size, int index, int count) {
    int *new_arr = (int *) realloc(*arr, (*size + count) * sizeof(int));

    for (int i = *size - 1; i >= index; i--) {
        new_arr[i + count] = new_arr[i];
    }

    for (int i = 0; i < count; i++) {
        new_arr[i + index] = rand() % 10 + 1;
    }

    *size += count;

    *arr = new_arr;
}