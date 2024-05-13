#include <iostream>

bool board[8][8];

bool tryQueen(int a, int b) {
    for (int i = 0; i < a; ++i) {
        if (board[i][b]) {
            return false;
        }
    }
    
    for (int i = 1; i <= a && b - i >= 0; ++i) {
        if(board[a - i][b - i]) {
            return false;
        }
    }
    
    for (int i = 1; i <= a && b + i < 8; i++) {
        if (board[a - i][b + i]) {
            return false;
        }
    }
    
    return true;
}
 
void setQueen(int a, int *cnt) 
{
    if (a == 8) {
        std::cout << "Result #" << ++(*cnt) << std::endl;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        return; 
    }
    
    for (int i = 0; i < 8; ++i) {
        if (tryQueen(a, i)) {
            board[a][i] = true;
            setQueen(a + 1, cnt);
            board[a][i] = false;
        }
    }
}
 
int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = false;
        }
    }

    int cnt = 0;

    setQueen(0, &cnt);

    std::cout << "Count of solves: " << cnt << std::endl;
    
    return 0;
}