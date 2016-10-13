#include <iostream>

int main() {
    int n;
    char inputch;
    scanf("%d %c", &n, &inputch);
    for (int i = 0; i < (n + 1) / 2; i++){
        printf("%c", inputch);
        for (int j = 1; j < n - 1; j++){
            if (i == 0 || i == (n + 1) / 2 - 1)
                printf("%c", inputch);
            else
                printf(" ");
        }
        printf("%c\n", inputch);
    }
    return 0;
}