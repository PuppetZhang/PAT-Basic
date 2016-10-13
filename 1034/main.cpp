#include <iostream>
#include <string.h>
struct number {
    long long int molecular;  //分子
    long long int denominator;//分母
};

void numprint(struct number number){
    if (number.denominator == 0){
        printf("Inf");
        return;
    }
    long long int divnum;     //除数
    long long int modnum;     //余数
    divnum = (number.molecular / number.denominator);
    modnum = (number.molecular % number.denominator);
    if (number.molecular < 0)
        printf("(");
    if (modnum == 0)
        printf("%lld", divnum);
    else {
        if (divnum != 0)
            printf("%lld %lld/%lld", divnum, modnum > 0 ? modnum : -modnum, number.denominator);
        else
            printf("%lld/%lld", modnum, number.denominator);
    }
    if (number.molecular < 0)
        printf(")");
}

long long int gcd ( long long int a,  long long int b){
    long long int max, min;
    max = a > b ? a : b;
    min = a < b ? a : b;
    a = max;
    b = min;
    long long int temp;
    while (a % b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}


void caladd(struct number number1, struct number number2, int op){
    int flag = (op == 1 ? 1 : -1);
    struct number result;
    long long int maxmolecular = number1.molecular * number2.denominator + flag * number2.molecular * number1.denominator;
    long long int maxdenominator = number2.denominator * number1.denominator;

    long long int temp =  maxmolecular >= 0 ? maxmolecular : -maxmolecular;

    if (temp != 0) {
        long long int gcdnum = gcd(maxdenominator, temp);
        maxmolecular /= gcdnum;
        maxdenominator /= gcdnum;
    }
    result.denominator = maxdenominator;
    result.molecular = maxmolecular;

    numprint(result);
}

void calmult(struct number number1, struct number number2, int op){
    struct number benumber, result;
    benumber = number2;
    if (benumber.molecular == 0){
        if (op == 3) {
            printf("0");
        }
        else{
            printf("Inf");
        }
    }
    else if (number1.molecular == 0){
        printf("0");
    }
    else {
        if (op == 4) {
            long long int temp;
            temp = benumber.denominator;
            benumber.denominator = benumber.molecular;
            benumber.molecular = temp;
        }
        long long int maxmolecular =  number1.molecular *  benumber.molecular;
        long long int maxdenominator =  number1.denominator *  benumber.denominator;
        int flag = (maxmolecular * maxdenominator >= 0 ? 1 : -1);
        maxmolecular = (maxmolecular >= 0 ? maxmolecular : -maxmolecular);
        maxdenominator = (maxdenominator >= 0 ? maxdenominator : -maxdenominator);

        long long int gcdnum = gcd(maxmolecular, maxdenominator);
        result.molecular = maxmolecular / gcdnum * flag;
        result.denominator = maxdenominator / gcdnum;

        numprint(result);
    }
}

void eqprint(struct number number1, struct number number2, long long int op){
    numprint (number1);
    switch (op){
        case 1: printf(" + "); break;
        case 2: printf(" - "); break;
        case 3: printf(" * "); break;
        case 4: printf(" / "); break;
    }
    numprint (number2);
    printf(" = ");

    if(op <= 2)
        caladd (number1, number2, op);
    else
        calmult (number1, number2, op);
    printf("\n");
}

int main() {
    struct number numbera, numberb;
    scanf("%lld/%lld %lld/%lld", &numbera.molecular, &numbera.denominator, &numberb.molecular, &numberb.denominator);

    eqprint(numbera, numberb, 1);
    eqprint(numbera, numberb, 2);
    eqprint(numbera, numberb, 3);
    eqprint(numbera, numberb, 4);

    return 0;
}