#include <iostream>

int linear_search(int *arr, int len, int elem);
int binary_search(int *arr, int len, int elem);
int interpolation_search(int *arr, int len, int elem);

int compare(const void *a, const void *b) {
    return (*(int*) a - *(int*) b); 
}

int main() {
    srand(time(nullptr));

    std::cout << "Input len of array: ";
    int len;
    std::cin >> len;

    int *arr = (int *) calloc(len, sizeof(int));
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % 201 - 100;
    }
    qsort(arr, len, sizeof(int), compare);
    
    std::cout << "Array: ";
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Input elem to search: ";
    int elem;
    std::cin >> elem;

    std::cout << "Linear search: " << linear_search(arr, len, elem) << std::endl;
    std::cout << "Binary search: " << binary_search(arr, len, elem) << std::endl;
    std::cout << "Interpolation search: " << interpolation_search(arr, len, elem) << std::endl;

    free(arr);

    return 0;
}

int linear_search(int *arr, int len, int elem) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] == elem) {
            return i;
        }
    }
    
    return -1;
}

int binary_search(int *arr, int len, int elem) {
    int left = 0;
    int right = len - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] == elem) {
            return mid;
        }
        
        else if (arr[mid] < elem) {
            left = mid + 1;
        } 
        
        else if (arr[mid] > elem) {
            right = mid - 1;
        }
    }

    return -1;
}

int interpolation_search(int *arr, int len, int elem) {
    int left = 0;
    int right = len - 1;
    int mid;

    while (arr[left] < elem && arr[right] > elem) {
        if (arr[left] == arr[right]) {
            break;
        }

        mid = left + ((elem - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[mid] < elem) {
            left = mid + 1;
        }

        else if (arr[mid] > elem) {
            right = mid - 1;
        }

        else {
            return mid;
        }
    }

    if (arr[left] == elem) {
        return left;
    }

    if (arr[right] == elem) {
        return right;
    }

    return -1;
}