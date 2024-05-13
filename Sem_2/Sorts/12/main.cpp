#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

void bucket_sort(int *arr, int len);
void counting_sort(int *arr, int len);
void merge_sort(int *arr, int l, int r);
void quick_sort(int *arr, int l, int r);
void output_array(int *arr, int len);

int main()
{
    srand(time(nullptr));

    std::cout << "Input len of array: ";
    int len;
    std::cin >> len;

    int *arr = (int *)calloc(len, sizeof(int));
    for (int i = 0; i < len; ++i)
    {
        arr[i] = rand() % 100;
    }

    output_array(arr, len);

    int *arr1 = (int *)calloc(len, sizeof(int));
    int *arr2 = (int *)calloc(len, sizeof(int));
    int *arr3 = (int *)calloc(len, sizeof(int));
    memcpy(arr1, arr, len * sizeof(int));
    memcpy(arr2, arr, len * sizeof(int));
    memcpy(arr3, arr, len * sizeof(int));

    bucket_sort(arr, len);
    counting_sort(arr1, len);
    merge_sort(arr2, 0, len - 1);
    quick_sort(arr3, 0, len - 1);

    std::cout << "Bucket sort: ";
    output_array(arr, len);
    std::cout << "Counting sort: ";
    output_array(arr1, len);
    std::cout << "Merge sort: ";
    output_array(arr2, len);
    std::cout << "Quick sort: ";
    output_array(arr3, len);

    free(arr);
    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}

void bucket_sort(int *arr, int len)
{
    if (len < 2)
    {
        return;
    }

    int max = arr[0], min = arr[0];

    for (int i = 1; i < len; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }

        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    if (max == min)
    {
        return;
    }

    std::vector<int> buckets[100];

    for (int i = 0; i < len; ++i)
    {
        int bucket_index = arr[i] * 10 / (max - min);
        buckets[bucket_index].push_back(arr[i]);
    }

    /*for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < buckets[i].size(); ++j) {
        std::cout << buckets[i][j] << " ";
      }
      std::cout << std::endl;
    }

    std::cout << "-" << std::endl;*/

    for (int i = 0; i < 100; ++i)
    {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    /*for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < buckets[i].size(); ++j) {
        std::cout << buckets[i][j] << " ";
      }
      std::cout << std::endl;
    }*/

    int index = 0;
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < buckets[i].size(); ++j)
        {
            arr[index++] = buckets[i][j];
        }
    }
}

void counting_sort(int *arr, int len)
{
    int *n_arr = (int *)calloc(len, sizeof(int));

    for (int i = 0; i < len; ++i)
    {
        int ind = 0;
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] <= arr[i])
            {
                ++ind;
            }
        }

        for (int j = i + 1; j < len; ++j)
        {
            if (arr[j] < arr[i])
            {
                ++ind;
            }
        }

        n_arr[ind] = arr[i];
    }

    for (int i = 0; i < len; ++i)
    {
        arr[i] = n_arr[i];
    }

    free(n_arr);
}

void merge(int arr[], int left, int mid, int right)
{
    int l = mid - left + 1, r = right - mid;

    int* larr = (int *) calloc(l , sizeof(int));
    int* rarr = (int *) calloc(r , sizeof(int));

    for (int i = 0; i < l; i++) 
    {
        larr[i] = arr[left + i];
    }
    
    for (int i = 0; i < r; i++) 
    {
        rarr[i] = arr[mid + 1 + i];
    }

    int lindex = 0, rindex = 0, mindex = left;

    while (lindex < l && rindex < r)
    {
        if (larr[lindex] <= rarr[rindex])
        {
            arr[mindex] = larr[lindex++];
        }

        else
        {
            arr[mindex] = rarr[rindex++];
        }

        mindex++;
    }

    while (lindex < l)
    {
        arr[mindex++] = larr[lindex++];
    }

    while (rindex < r)
    {
        arr[mindex++] = rarr[rindex++];
    }
    
    free(larr);
    free(rarr);
}
void merge_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int *arr, int low, int high, int pivot) 
{
    int q = low;
    for (int i = low;i <= high;i++) {
        if (arr[i] <= pivot) 
        {
            int tmp = arr[q];
            arr[q] = arr[i];
            arr[i] = tmp;
            ++q;
        }
    }
    --q;
    return q;
}
void quick_sort(int *arr, int l, int r)
{
    if (l < r)
    {
        int pivot = arr[r];
        int q = partition(arr, l, r, pivot);
        quick_sort(arr, l, q - 1);
        quick_sort(arr, q + 1, r);
    }
}

void output_array(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
