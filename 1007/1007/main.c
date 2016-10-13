//
//  main.c
//  1007
//
//  Created by 摆线木偶 on 16/8/1.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int oddNum[100005];
int oddn = 0;

//odd calculate all odd which smaller than n, then restore in the oddNum
void odd(int n){
    for (int i = 2; i <= n; i++){
        int flag = 0;
        for (int j = 2; j < sqrt(i) + 1; j++){
            if (i % j == 0){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            oddNum[oddn++] = i;
        }
    }
}
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    odd(n);
    /* 
    //test if calculate odd number is right
    for (int i = 0; i < oddn; i++){
        printf("%d\n", oddNum[i]);
    }
     */
    int count = 0;
    for (int i = 1; i < oddn; i++){
        if (oddNum[i] - oddNum[i - 1] == 2){
            count ++;
        }
    }
    
    printf("%d\n", count);
    return 0;
}
