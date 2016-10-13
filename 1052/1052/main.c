//
//  main.c
//  1052
//
//  Created by 摆线木偶 on 16/8/2.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>
#include "string.h"
#define hand 0
#define eye 1
#define mouth 2

#define off 0
#define on 1

int main(int argc, const char * argv[]) {
    char str[3][15][5] = {};
    int count[3] = {0, 0, 0};
    //    char temp[100];
    char input;
    
    /*
     type used to be determined hand|eye|mouse
     flag used to be determined whether this input char belong to []
     order used to know how many char are there in the inputing exp
     */
    int type = hand, flag = off, order = 0;
    while (scanf("%c", &input)){
        if (input == '\n'){
            type ++;
            if (type > 2)
                break;
        }
        else if (input == '['){
            count[type]++;
            order = 0;
            flag = on;
        }
        else if (input == ']')
            flag = off;
        else if (flag == on){
            str[type][count[type]][order] = input;
            order ++;
        }
    }
    /*
     //input test
     for (int i = 0; i < 3; i++){
     for (int j = 0; j < count[i]; j++){
     printf("%s ", str[i][j]);
     }
     printf("\n");
     }
     */
    
    int n, choice[5];
    scanf("%d", &n);
    while (n --){
        flag = on;
        for (int j = 0; j < 5; j++){
            scanf ("%d", &choice[j]);
            int temp = j - 2 > 0 ? j - 2 : 2 - j;
            if (temp == 2){
                if (choice[j] > count[hand] || choice[j] < 1){
                    flag = off;
                }
            }
            else if (temp == 1){
                if (choice[j] > count[eye] || choice[j] < 1){
                    flag = off;
                }
            }
            else {
                if (choice[j] > count[mouth] || choice[j] < 1){
                    flag = off;
                }
            }
            
        }
        if (flag == off){
            printf("Are you kidding me? @\\/@\n");
        }
        else{
            for (int j = 0; j < 5; j++){
                int temp = j - 2 > 0 ? j - 2 : 2 - j;
                if (temp == 2){
                    if (j - 2 < 0)
                        printf("%s(", str[hand][choice[j]]);
                    else
                        printf(")%s\n", str[hand][choice[j]]);
                    
                }
                else if (temp == 1){
                    printf("%s", str[eye][choice[j]]);
                }
                else {
                    
                    printf("%s", str[mouth][choice[j]]);
                }
            }
        }
    }
    return 0;
}
