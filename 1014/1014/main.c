//
//  main.c
//  1014
//
//  Created by 摆线木偶 on 16/8/1.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char str[4][61];
    int len[4];
    int week = 0, hour = 0, minute = 0;
    for (int i = 0; i < 4; i++){
        scanf("%s", str[i]);
        len[i] = strlen(str[i]);
    }
    
    //determine week
    int i = 0;
    for (; i < (len[0] > len[1] ? len[1] : len[0]); i++) {
        if (str[0][i] == str[1][i] && str[0][i] <= 'G' && str[0][i] >= 'A') {
            week = str[1][i] - 'A' + 1;
            break;
        }
    }
    switch (week) {
        case 1:
            printf("MON ");
            break;
        case 2:
            printf("TUE ");
            break;
        case 3:
            printf("WED ");
            break;
        case 4:
            printf("THU ");
            break;
        case 5:
            printf("FRI ");
            break;
        case 6:
            printf("SAT ");
            break;
        case 7:
            printf("SUN ");
            break;
//        default:
//            printf("Week Err\n");
//            break;
    }
    
    // determine hour
    for (i = i + 1; i < (len[0] > len[1] ? len[1] : len[0]); i++) {
        if (str[0][i] == str[1][i]) {
            
            if (str[0][i] <= '9' && str[0][i] >= '0')
                hour = str[0][i] - '0';
            else if (str[0][i] <= 'N' && str[0][i] >= 'A')
                hour = str[0][i] - 'A' + 10;
            else
                continue;
//               printf("Err");
            break;
        }
    }
    if (hour <= 9)
       printf("0");
    printf("%d:", hour);
    
    
    // determine minute
    for (i = 0; i < (len[2] > len[3] ? len[3] : len[2]); i++) {
        if (str[2][i] == str[3][i]) {
            
            if ( (str[2][i] <= 'z' && str[2][i] >= 'a') || (str[2][i] <= 'Z' && str[2][i] >= 'A') ) {
                minute = i;
                break;
            }
        }
    }
    if (minute <= 9)
       printf("0");
    printf("%d\n", minute);
    
    
    return 0;
}
