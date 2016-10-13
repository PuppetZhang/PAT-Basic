//
//  main.c
//  1009
//
//  Created by 摆线木偶 on 16/8/3.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char input[83] = {'\0'}, tmp;
    int node[83];
    int noden = 1, i = 0;
    while ( scanf("%c", &tmp) != EOF){
        input[i] = tmp;
        if (tmp == ' '){
            node[noden ++] = i;
        }
        i++;
    }
    if (input[i - 1] == '\n'){
        i--;
    }
    input[i++] = ' ';
    if (input[0] != ' '){
        node[0] = -1;
    }
    else {
        for (i = 0; i < noden - 1; i++)
            node[i] = node[i + 1];
        noden --;
    }
    for (i = noden - 1; i >= 0; i--){
        int temp = node[i] + 1;
        while (input[temp] != ' '){
            printf("%c", input[temp]);
            temp++;
        }
        if (i != 0)
            printf(" ");
        else{
            printf("\n");
        }
    }
    
    return 0;
}
