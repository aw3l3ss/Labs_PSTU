#include <iostream>

using namespace std;

void init_array(int *arr[], int n, int m);
void print_array(int *arr[], int n, int m);
void format_array(int *arr[], int *n, int m, int a, int b);

int main()
{
    srand(time(nullptr));

    int n = rand() % 10 + 1, m = rand() % 10 + 1;
    int *arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    int a = rand() % n, b = (rand() % (n - a)) + a;

    init_array(arr, n, m);
    print_array(arr, n, m);
    cout << endl << "Delete from " << a << " to " << b << endl;
    format_array(arr, &n, m, a, b);
    print_array(arr, n, m);

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }

    return 0;
}

void init_array(int *arr[], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 10;
        }
    }
}

void print_array(int *arr[], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void format_array(int *arr[], int *n, int m, int a, int b) {
    for (int i = a; i - a + b < *n; i++) {
        arr[i] = arr[i - a + b];
    }

    *n -= (b - a);
}