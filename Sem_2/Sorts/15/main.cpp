#include <iostream>

int getIndex(int* arr, int* arr2, int n) {
    int cnt = 0;
    arr2[cnt++] = 0;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] < arr[i]) {
            arr2[cnt++] = i + 1;
        }
    }

    return cnt;
}

void merge(int* arr, int* arr2, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            arr2[k++] = arr[i++];
        }

        else {
            arr2[k++] = arr[j++];
        }
    }

    while (i <= m) {
        arr2[k++] = arr[i++];
    }

    while (j <= r)	{
        arr2[k++] = arr[j++];
    }
}

void mergePass(int* arr, int* arr2, int* arr3, int s, int n, int cnt) {
    int i = 0;

    while (i <= cnt - 2 * s) {
        if (i + 2 * s < cnt) {
            merge(arr, arr2, arr3[i], arr3[i + s] - 1, arr3[i + 2 * s] - 1);
        }

        else {
            merge(arr, arr2, arr3[i], arr3[i + s] - 1, n - 1);
        }

        i = i + 2 * s;
    }

    if (i + s < cnt) {
        merge(arr, arr2, arr3[i], arr3[i + s] - 1, n - 1);
    }

    else if (i < cnt) {
        for (int j = arr3[i]; j <= n - 1; j++) arr2[j] = arr[j];
    }
}

void mergeSort(int* a, int* t, int n, int cnt)
{
    int b[100];
    int s = 1;
    while (s < cnt)
    {
        mergePass(a, b, t, s, n, cnt);
        s += s;
        mergePass(b, a, t, s, n, cnt);
        s += s;
    }
}

int main()
{
    srand(time(NULL));

    int n;
    std::cout << "Input array size: ";
    std::cin >> n;

    int* arr = (int *) calloc(n, sizeof(int));
    int* arr2 = (int *) calloc(n, sizeof(int));

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }

    std::cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int cnt = getIndex(arr, arr2, n);
    mergeSort(arr, arr2, n, cnt);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    free(arr);
    free(arr2);

    return 0;
}