#include <iostream>

int main() {
    int n;
    char ch;
//    while(1) {
        scanf("%d %c", &n, &ch);
        int num = 1, tempi;
        for (tempi = 3;; tempi += 2) {
            num += tempi * 2;
            if (num > n)
                break;

        }

        num -= tempi * 2;
        tempi -= 2;
        for (int i = 0; i < tempi; i++) {
            for (int j = 0; j < tempi; j++) {
                if ((tempi - i - 1 > j && i > j) || (tempi - j - 1 < i && i < j))
                    printf(" ");
                else
                    printf("%c", ch);
            }
            printf("\n");
        }
        printf("%d\n", n - num);
//    }
    return 0;
}