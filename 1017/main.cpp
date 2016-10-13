#include <iostream>
#include <string.h>
int main() {
    char inputa[10005], outputq[10005];
    int inputb, outputr = 0;
    scanf("%s", &inputa);
    scanf("%d", &inputb);
    int len = strlen(inputa);
    for (int i = 0, j = 0 ; i < len; i++){
        outputr = outputr * 10 + inputa[i] - '0';
        outputq[j++] = outputr / inputb + '0';
        if (outputr / inputb == 0 && j - 1 == 0)
            j --;
        outputr = outputr % inputb;
        //printf("%c %d\n", outputq[j - 1], outputr);
    }
    printf("%s %d", outputq, outputr);
    return 0;
}