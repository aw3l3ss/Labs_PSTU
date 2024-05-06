#include <iostream>
#include <string.h>
#include <readline/readline.h>

int kmp(char *s, char *p);

int main() {
    char *s, *p;
    std::cout << "Input string: ";
    s = readline(NULL);
    std::cout << "Input substring: ";
    p = readline(NULL);

    std::cout << kmp(s, p) << std::endl;

    free(s);
    free(p);

    return 0;
}

int kmp(char *s, char *p) {
    int len_s = strlen(s);
    int len_p = strlen(p);

    int *arr = (int*) calloc(len_p, sizeof(int));

    arr[0] = 0;

    int j = 0;
    for (int i = 1; i < len_p; ++i) {
        while (j > 0 && p[j] != p[i]) {
            j = arr[j - 1];
        }

        if (p[j] == p[i]) {
            ++j;
        }

        arr[i] = j;
    }

    j = 0; 
    for (int i = 0; i < len_s; ++i) {
        while (j > 0 && s[i] != p[j]) {
            j = arr[j - 1];
        }

        if (p[j] == s[i]) {
            ++j;
        }

        if (j == len_p) {
            free(arr);

            return i - j + 1;
        }
    }

    free(arr);

    return -1;
}