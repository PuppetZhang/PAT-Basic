//
//  main.c
//  1054
//
//  Created by 摆线木偶 on 16/8/4.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define ON 1;
#define OFF 0;
#define POSITIVE 1;
#define NEGATIVE -1;

int main(int argc, const char * argv[]) {
    int n, numCount = 0;
    scanf ("%d", &n);
    char inputNum[101][101];
    float tureNum[101];
    for (int i = 0; i < n; i++){
        scanf ("%s", inputNum[i]);
        int len = strlen(inputNum[i]);
        tureNum[numCount] = 0.0;
        int flag = ON;
        float mult = 1.0;
        int PandN = 1;
        //check the inputNum & store into tureNum if check pass
        for (int j = 0; j < len; j++){
            
            //if and only if +|- appears in the first its right
            if (inputNum[i][j] == '+' || inputNum[i][j] == '-'){
                if (j == 0){
                    PandN = (inputNum[i][j] == '+' ? 1 : -1);
                }
                else{
                    flag = OFF;
                }
                
            }
            
            // '.' can't appear twice, if it's first appear the follow num should be:
            // x + num * mult;
            // mult = mult * 0.1;
            else if (inputNum[i][j] == '.'){
                if (mult == 1.0){
                    mult = 0.1;
                }
                else{
                    flag = OFF;
                }
            }
            
            //first check if this num have point
            //second check if there are more than two point;
            //last be sure the num shouldn't bigger than 1000.00
            else if (inputNum[i][j] <= '9' && inputNum[i][j] >= '0'){
                if (mult == 1.0){
                    tureNum[numCount] = tureNum[numCount] * 10.0 + inputNum[i][j] - '0';
                }
                else {
                    if (mult > 0.005){
                        tureNum[numCount] = tureNum[numCount] + mult * (inputNum[i][j] - '0');
                        mult = mult * 0.1;
                    }
                    else{
                        flag = OFF;
                    }
                }
                if (tureNum[numCount] > 1000.0){
                    flag = OFF;
                }

            }
            
            else{
                flag = OFF;
            }
            
            if (!flag){
                break;
            }
        }
        if (flag == 0){
            printf("ERROR: %s is not a legal number\n", inputNum[i]);
        }
        else {
            tureNum[numCount] = tureNum[numCount] * PandN;
            numCount++;
        }

    }
    
    if (numCount == 0){
        printf("The average of 0 numbers is Undefined\n");
    }
    else if (numCount == 1){
        printf("The average of 1 number is %.2f\n", tureNum[0]);
    }
    else{
        float average = 0.0;
        for (int i = 0; i < numCount; i++){
            average += tureNum[i];
        }
        average /= numCount;
        printf("The average of %d numbers is %.2f\n", numCount, average);
    }
    
    return 0;
}
