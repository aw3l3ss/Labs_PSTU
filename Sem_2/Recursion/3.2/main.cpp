#include <iostream>

int fibonacci(int x) {
    if (x == 0) {
        return 0;
    }

    if (x == 1) {
        return 1;
    }

    return fibonacci(x - 1) + fibonacci(x - 2);
}

int main() {
    int n;
    std::cin >> n;

    std::cout << fibonacci(n) << std::endl;

    return 0;
}