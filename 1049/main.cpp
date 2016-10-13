#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    double sum = 0.0, input;
    for (int i = 1;i <= n; i++) {
        scanf("%lf", &input);
//        int base = ;
        sum += input * (n - i + 1) * i;
//        printf("%.2f\n", sum);
    }
    printf("%.2lf\n", sum);
    return 0;
}


//float 不行 需换double