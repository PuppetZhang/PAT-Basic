//
//  main.c
//  1012
//
//  Created by 摆线木偶 on 16/8/19.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a[5] = {0}, temp, flag[5] = {0};   //a0 空,1-5对应题目中的1-5
    int n = 0;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &temp);
        if (temp % 10 == 0) {
            a[0] += temp;
            flag[0] = 1;
        }
        else if (temp % 5 == 1){
            flag[1] ++;
            a[1] += (flag[1] % 2 == 0 ? -1 : 1) * temp;
        }
        else if (temp % 5 == 2){
            flag[2] ++;
            a[2] ++;
        }
        else if (temp % 5 == 3){
            flag[3] ++;
            a[3] += temp;
        }
        else if (temp % 5 == 4){
            flag[4] = 1;
            a[4] = a[4] > temp ? a[4] : temp;
        }
    }
    
    
    for (int i = 0; i < 5; i++) {
        if (flag[i] == 0)
            printf("N");
        else if (i == 3){
            float out = (float) a[3];
            printf("%.1f", out / (float) flag[3]);
        }
        else
             printf("%d", a[i]);
        
        if (i != 4)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}
