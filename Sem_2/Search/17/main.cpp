#include <iostream>
#include <string.h>
#include <readline/readline.h>

const int CHAR_NUM = 256;

void kmp(char *s, char *p);
void bm(char *s, char *p);

int main() {
    char *s, *p;
    std::cout << "Input string: ";
    s = readline(NULL);
    std::cout << "Input substring: ";
    p = readline(NULL);

    std::cout << std::endl << "Knuth-Morris-Pratt: ";
    kmp(s, p);

    std::cout << "Boyer-Moore: ";
    bm(s, p);

    free(s);
    free(p);

    return 0;
}

void calcCharTable(char *s, int size, int charTable[CHAR_NUM]) {
    for (int i = 0; i < CHAR_NUM; i++) {
        charTable[i] = -1;
    }
    
    for (int i = 0; i < size; i++) {
        charTable[(int) s[i]] = i;
    }
}

void bm(char *s, char *p) {
    int s_size = strlen(s);
    int p_size = strlen(p);

    int shift_table[CHAR_NUM];

    calcCharTable(s, p_size, shift_table);

    int shift = 0;

    while (shift <= (s_size - p_size)) {
        int j = p_size - 1;

        while (j >= 0 && p[j] == s[shift+j]) { 
            --j; 
        }

        if (j < 0) {
            std::cout << shift << " ";
            
            if (shift + p_size < s_size) {
                shift += p_size - shift_table[(int) s[shift + p_size]];
            }

            else {
                ++shift;
            }
        }

        else {
            shift += std::max(1, j - shift_table[(int) s[shift + j]]);
        }
    }

    std::cout << std::endl;
}

int* calcPrefixFunc(char *p, int size) {
    int* lps = (int *) calloc(size, sizeof(int));
    int len = 0, i = 1;

    lps[0] = 0;

    while (i < size) {
        if (p[i] == p[len]) {
            lps[i++] = len++;
        }

        else {
            if (len != 0) { 
                len = lps[len - 1]; 
            }

            else {
                lps[i++] = 0;
            }
        }
    }

    return lps;
}

void kmp(char *s, char *p)
{
    int s_size = strlen(s);
    int p_size = strlen(p);

    int* lps = calcPrefixFunc(p, p_size);

    int s_idx = 0;
    int p_idx = 0;

    while ((s_size - s_idx) >= (p_size - p_idx)) {
        if (p[p_idx] == s[s_idx]) {
            ++p_idx;
            ++s_idx;
        }

        if (p_idx == p_size) {
            std::cout << s_idx - p_idx << " ";
            p_idx = lps[p_idx - 1];
        }

        else if (s_idx < s_size && p[p_idx] != s[s_idx]) {
            if (p_idx != 0) { 
                p_idx = lps[p_idx - 1]; 
            }

            else { 
                ++s_idx;
            }
        }
    }

    free(lps);
    std::cout << std::endl;
}