#include <iostream>

void hanoi(int n, int a, int b, int c, int *cnt) {
    if (n == 1) {
        std::cout << a << "->" << c << std::endl;
        ++(*cnt);
    } 
    
    else {
        hanoi(n - 1, a, c, b, cnt);
        std::cout << a << "->" << c << std::endl;
        ++(*cnt);
        hanoi(n - 1, b, a, c, cnt);
    }
}

int main() {
    int n;
    std::cin >> n;

    int cnt = 0;

    hanoi(n, 1, 2, 3, &cnt);
    std::cout << "Steps: " << cnt << std::endl;
    
    return 0;
}