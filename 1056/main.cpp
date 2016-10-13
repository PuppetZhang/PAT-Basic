#include <iostream>

int main() {
    int num, input;
    double result = 0.0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        scanf("%d", &input);
        result += (double) input;
    }
    result = result * (double) (num - 1) * 11.0;
    printf("%.0lf\n", result);
    return 0;
}