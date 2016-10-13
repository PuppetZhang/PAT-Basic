#include <iostream>
#include <string.h>



int main() {
    char stra[12], strb[12];
    int numa, numb;
    int num1 = 0, num2 = 0;
    scanf("%s %d %s %d", &stra, &numa, &strb, &numb);
    for (int i = 0; i < strlen(stra); i++){
        if (stra[i] - '0' == numa){
            num1 = num1 * 10 + numa;
        }
    }
    for (int i = 0; i < strlen(strb); i++){
        if (strb[i] - '0' == numb){
            num2 = num2 * 10 + numb;
        }
    }
    printf("%d", num1 + num2);
    return 0;
}