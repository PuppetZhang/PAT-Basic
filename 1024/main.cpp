#include <iostream>
#include <string.h>

int main() {
    char input[100021];
    scanf("%s", &input);
    int len = strlen(input);

    /*
     * deal data
     * base = (char) norpFlag + (char[]) output
     * exponent = (int)expflag + (int) exp
    */
    char norpFlag = '+'; // positive = '+' & negative = '-'
    norpFlag = input[0];
    char output[100021] = {'\0'};
    int outputnum = 0, baseOrExponent = 1;//base = 1, exponent = -1
    int exp = 0, expflag = '+';// exp's positive = 1 & exp's negative = -1
    for (int i = 1; i < len; i++){
        if (input[i] == '.'){
            continue;
        }
        else if (input[i] == 'E'){
            baseOrExponent = -1;
            i++;
            if (input[i] == '-')
                expflag = -1;
        }
        else {
            if (baseOrExponent == 1)
                output[outputnum++] = input[i];
            else{
                exp = exp * 10 + input[i] - '0';
            }
        }
    }

//    printf("%c%s\n", norpFlag, output);
//    printf("%c%d\n", expflag, exp);

    if(norpFlag == '-')
        printf("%c", norpFlag);

    if (expflag != -1 || exp == 0){
        for (int i = 0; i < outputnum; i++){
            printf("%c", output[i]);
            if (i == exp && i != outputnum - 1)
                printf(".");
        }
        if (outputnum < exp){
            for (int i = 0; i <= exp - outputnum; i++)
                printf("0");
        }
    }
    else{
        printf("0.");
        for(int i = 1; i < exp; i++)
            printf("0");
        printf("%s", output);

    }

    return 0;
}