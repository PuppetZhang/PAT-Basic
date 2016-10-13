//
//  main.c
//  1006
//
//  Created by 摆线木偶 on 16/8/1.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>

void p(int x, int type){
    for (int i = 0; i < x; i++){
        switch(type){
            case 1: printf("B"); break;
            case 2: printf("S"); break;
            case 3: printf("%d", i + 1); break;
            default: printf("err"); break;
        }
    }
}

int main(int argc, const char * argv[]) {
    int num;
    scanf("%d", &num);
    int hundreds, decade, bit;
    hundreds = num / 100;
    num = num % 100;
    decade = num / 10;
    num = num % 10;
    bit = num;
    p(hundreds, 1);
    p(decade, 2);
    p(bit, 3);
    printf("\n");
    return 0;
}
