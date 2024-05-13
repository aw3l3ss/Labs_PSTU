#include <iostream>

int main() {
    int n;
    std::cout << "Count number of columns and rows: ";
    std::cin >> n;

    int arr[n][n];

    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 1) {
                arr[i][j] = 0;
            }

            else {
                arr[i][j] = k++;
            }

            if (k == 10) {
                k = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}