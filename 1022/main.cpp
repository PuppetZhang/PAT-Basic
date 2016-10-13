#include <iostream>
#include <math.h>
int main() {
    double a, b;
    double d;
    scanf("%lf %lf %lf", &a, &b, &d);
    double max = 1, sum = a + b;
    while (max * d <= sum)
        max = max * d;
//   printf("%lf %lf\n", sum, max);
    while (max >= 1){
//        printf("%17lf    /    ", sum);
//        printf("%17lf    =    ", max);
//        printf("%17.0lf    ……    ", floor(sum / max));
        printf("%.0lf", floor(sum / max));
        sum = sum - (floor(sum / max)) * max;
//        printf("%17.0lf    \n", sum);
        max = max / d;
    }
    return 0;
}




//考虑极小和次小情况