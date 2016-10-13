//
//  main.c
//  1004
//
//  Created by 摆线木偶 on 16/7/31.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    struct node {
        char name[15];
        char no[15];
        int score;
    } max,min,input;
    max.score = -1;
    min.score = 101;
    scanf("%d", &n);
    while (n--){
        scanf ("%s %s %d", &input.name, &input.no, &input.score);
        if (input.score > max.score)
            max = input;
        if(input.score < min.score)
            min = input;
    }
    printf("%s %s\n", max.name, max.no);
    printf("%s %s\n", min.name, min.no);

    return 0;
}
