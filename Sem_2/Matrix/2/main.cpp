#include <iostream>

int main() {
    int n;
    std::cout << "Count number of columns and rows: ";
    std::cin >> n;

    int arr[n][n];

    for (int i = 0; i < n; i++) {
        int k = 1;
        
        for (int j = n - 1; j >= 0; j--) {
            if (j <= i) {
                arr[i][j] = k++;
            }

            else {
                arr[i][j] = 0;
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