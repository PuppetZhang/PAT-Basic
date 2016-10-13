#include <iostream>
#include <string.h>

int main() {
    char input[100005];
    double p[100005], t[100005];
    scanf("%s", &input);
    int len = strlen(input);
    double pnum = 0.0, tnum = 0.0;
    for (int i = 0; i < len; i++){
        p[i] = pnum;
        if (input[i] == 'P'){
            pnum ++;
        }
    }
    for (int i = len - 1; i >= 0; i--){
        t[i] = tnum;
        if (input[i] == 'T'){
            tnum ++;
        }
    }

    double num = 0;
    for (int i = 0; i < len; i++){
        if (input[i] == 'A')
            num += p[i] * t[i];
        while (num >= 1000000007){
            num -= 1000000007;
        }
    }

    printf("%.0lf", num);

    
    return 0;
}