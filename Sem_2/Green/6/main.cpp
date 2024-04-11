#include <iostream>
#include <cstring>

#define MAX_STR_LEN 255

using namespace std;

void Gets(char **string);
void task(char *str);

int main()
{
    char *str = NULL;
    Gets(&str);
    task(str);
    free(str);
    return 0;
}

void Gets(char **string) {
    if (*string) {
        free(*string);
    }

    char *str = (char *) calloc(MAX_STR_LEN + 1, sizeof(char));

    char ch = getchar();
    int i = 0;
    while (ch != '\n') {
        str[i] = ch;
        i++;

        ch = getchar();
    }
    str[i] = '\0';

    *string = str;
}

void task(char *str) {
    char *word = strtok(str, " ");

    while (word != NULL) {
        int cnt = 0;

        for (int i = 0; i < strlen(word); i++) {
            if (isdigit(word[i])) {
                cnt++;
            }
        }

        if (cnt == 1) {
            cout << word << " ";
        }

        word = strtok(NULL, " ");
    }

    cout << endl;
}