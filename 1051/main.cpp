#include <stdio.h>
#include <math.h>

int main() {
    float r1, p1, r2, p2;
    scanf("%f %f %f %f", &r1, &p1, &r2, &p2);
    float realpart = 0.0, voidpart = 0.0;
    float r = r1 * r2;
    realpart = r1 * r2 * cos(p1) * cos(p2) - r1 * r2 * sin(p1) * sin(p2);
    voidpart = r1 * r2 * cos(p1) * sin(p2) + r1 * r2 * sin(p1) * cos(p2);
    if (realpart + 0.005 >= 0 && realpart < 0){
        printf("0.00");
    }
    else{
        printf("%.2f", realpart);
    }


    if (voidpart >= 0) {
        printf("+%.2fi\n", voidpart);
    }
    else if (voidpart + 0.005 >= 0 && voidpart < 0){
        printf("+0.00i\n");
    }
    else{
        printf("%.2fi\n", voidpart);
    }
    return 0;

}
//2.3 +3.5 5.2 0.4
