//
//  main.c
//  1002
//
//  Created by 摆线木偶 on 16/7/31.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int sum[10002], max = 0;
    for (int i = 0; i < 10002; i++)
        sum[i] = 0;
    char input;
    while (scanf("%c", &input)){
        if (!(input <= '9' && input >= '0'))
            break;
        int in = input - '0';
        int add = in;
        int t = 0;
        while (add != 0){
            sum[t] += add;
            if (sum[t] > 9){
                sum[t] -= 10;
                t++;
                add = 1;
            }
            else
                add = 0;
        }
        if (t > max)
            max = t;
    }
    for (int i = max; i >= 0; i--){
        switch(sum[i]){
            case 0: printf("ling");break;
            case 1: printf("yi");break;
            case 2: printf("er");break;
            case 3: printf("san");break;
            case 4: printf("si");break;
            case 5: printf("wu");break;
            case 6: printf("liu");break;
            case 7: printf("qi");break;
            case 8: printf("ba");break;
            case 9: printf("jiu");break;
            default: printf("err");break;
        }
        if (i != 0)
            printf(" ");
        else
            printf("\n");
    }
    
    return 0;
}
