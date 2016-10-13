//
//  main.c
//  1003
//
//  Created by 摆线木偶 on 16/7/31.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int firstcheck(char str[]){
    int len = strlen(str);
    int result = 1, pcount = 0, acount = 0, tcount = 0;
    for (int i = 0; i < len; i++){
        if (str[i] == 'P')
        {
            pcount ++;
            //there are more than one P or T is former than P
            if (pcount > 1 || tcount != 0){
                result = 0;
                break;
            }
        }
        else if (str[i] == 'A'){
            acount ++;
        }
        else if (str[i] == 'T')
        {
            tcount ++;
            //there are more than one T or T is follow next to P
            if (tcount > 1 || str[i - 1] == 'P'){
                result = 0;
                break;
            }
        }
        else {
            result = 0;
            break;
        }
    }
    //there are no p|a|t
    if (acount == 0 || pcount == 0 || tcount == 0)
        result = 0;
    return result;
}

int secondcheck(char str[]){
    int len = strlen(str);
    int result = 1, ploc = -1, tloc = -1;
    
    for (int i = 0; i < len; i++){
        if (str[i] == 'P')
            ploc = i;
        else if (str[i] == 'T')
            tloc = i;
    }
    if (ploc == 0 && tloc == len - 1)
        return 1;
    //check
    else {
        if ((len - tloc - 1) % ploc == 0 && (len - tloc - 1) / ploc == tloc - ploc - 1){
            int x = (len - tloc) / ploc;
            int y = tloc - ploc - 1;
            result = 1;
        }
        else
            result = 0;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    int num = 0;
    scanf("%d", &num);
    char str[104];
    while (num--){
        scanf("%s", str);
        int result = -1;
        
        //1. check if there are !PAT in str.
        //2. check if there are be only one P and only one T in str.
        //3. check if there are A in str
        //4. P'loc should former than T'loc
        //5. T shouldn't follow next to P
        result = firstcheck(str);
        
        if (result == 0){
            printf("NO\n");
            continue;
        }
        
        //aim to continue reduce aPbATca to aPbTc until PAT
        result = secondcheck(str);
        
        if (result == 0){
            printf("NO\n");
            continue;
        }
        else
            printf("YES\n");
    }
    return 0;
}
