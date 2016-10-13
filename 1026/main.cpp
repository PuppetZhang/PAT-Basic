#include <iostream>
#include <math.h>

int main() {
    float c1, c2;
    scanf("%f %f", &c1, &c2);
    float det = c2 - c1;
    int temp = (det / 100 - floor(det / 100)) * 100;
    det = floor(det / 100) + (temp < 50 ? 0.0 : 1.0);

    float hour = floor (det / 3600);
    det = det - hour * 3600;

    float minute = floor (det / 60);
    det = det - minute * 60;

    float second = det;

    printf("%02.0f:%02.0f:%02.0f\n", hour, minute, second);

    return 0;
}