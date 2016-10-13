//
//  main.c
//  1001
//
//  Created by 摆线木偶 on 16/7/31.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n, count;
    scanf("%d", &n);
    count = 0;
    while(n != 1){
        if (n % 2 == 0)
            n = n /2;
        else
            n = (3 * n + 1) / 2;
        count ++;
    }
    printf("%d\n", count);
    return 0;
}
