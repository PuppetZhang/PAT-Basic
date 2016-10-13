//
//  main.c
//  1008
//
//  Created by 摆线木偶 on 16/8/3.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num, moveNum;
    int arr[105];
    scanf ("%d %d", &num, &moveNum);
    for (int i = 0; i < num; i++){
        scanf ("%d", &arr[i]);
    }
    int start = num - moveNum % num;
    for (int i = 0; i < num - 1; i++)
        printf("%d ", arr[(start + i) % num]);
    printf("%d\n", arr[(start + num - 1) % num]);
    return 0;
}
