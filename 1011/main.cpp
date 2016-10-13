#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    long int a, b, c;
    for (int i = 1; i <= n; i++) {
        scanf("%ld %ld %ld", &a, &b, &c);
        if (a + b > c){
            printf("Case #%d: true\n", i);
        }
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}