// after read other's ideas get the special situation:"9 0", which should output "0 0"



//
//  main.c
//  1010
//
//  Created by 摆线木偶 on 16/8/3.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//


// after read other's ideas

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x = 0, y, z;
    int i = 0, flag = 0;
    while (scanf ("%d," ,&z) != EOF){
        if (i % 2 == 0)
            x = z;
        else{
            y = z;
            if (y != 0){
                if (i == 1){
                    printf("%d %d", x * y, y - 1);
                    flag = 1;
                }
                else {
                    printf(" %d %d", x * y, y - 1);
                    flag = 1;
                }
            }
        }
        i++;
    }
    /*
    while (scanf ("%d %d", &x, &y) != EOF){
        if (y != 0 && x != 0){
            if (i == 0){
                printf("%d %d", x * y, y - 1);
            }
            else {
                printf(" %d %d", x * y, y - 1);
            }
        }
        i++;
    }
     */

    if (flag == 0){
        printf("0 0");
    }
    printf("\n");
    return 0;
}
