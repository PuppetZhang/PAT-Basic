//
//  main.c
//  1043
//
//  Created by 摆线木偶 on 16/8/1.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>
int chech(char a, char b){
    return a - b == 0 ? 0 : 1;
}
int main(int argc, const char * argv[]) {
    char input;
    int pcount = 0, acount = 0, Tcount = 0, ecount = 0, scount = 0, tcount = 0;
    while (scanf("%c", &input) != EOF){
        if (input != 'P' && input != 'A' && input != 'T' && input != 'e' && input != 's' && input != 't')
            continue;
        else{
            if (input == 'P')
                pcount ++;
            else if (input == 'A')
                acount ++;
            else if (input == 'T')
                Tcount ++;
            else if (input == 'e')
                ecount ++;
            else if (input == 's')
                scount ++;
            else if (input == 't')
                tcount ++;
        }
    }
        while (pcount > 0 || acount > 0 || Tcount > 0 || ecount > 0 || scount > 0 || tcount > 0){
            if (pcount != 0){
                printf("P");
                pcount --;
            }
            if (acount != 0){
                printf("A");
                acount --;
            }
            if (Tcount != 0){
                printf("T");
                Tcount --;
            }
            if (ecount != 0){
                printf("e");
                ecount --;
            }
            if (scount != 0){
                printf("s");
                scount --;
            }
            if (tcount != 0){
                printf("t");
                tcount --;
            }
        }
        printf("\n");
            
    return 0;
}
