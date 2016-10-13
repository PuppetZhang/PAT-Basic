//
//  main.c
//  1005
//
//  Created by 摆线木偶 on 16/8/1.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>
int n, check[105];
void sort(int chack[], int left, int right){
    if (left >= right)
        return;
    int i = left, j = right, key = check[left];
    while (i < j){
        while (i < j & check[j] <= key)
            j--;
        check[i] = check[j];
        while (j > i & check[i] >= key)
            i++;
        check[j] = check[i];
        check[i] = key;
        sort(check, left, i - 1);
        sort(check, i + 1, right);
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    
    for (int i = 0; i < 105; i++){
        if (i < n)
            scanf("%d", &check[i]);
        else
            check[i] = -1;
    }
    //    sort(check, 0, n);
    
    for (int i = n - 1; i >= 0; i--){
        if (check[i] == -1) //if the number is covered, it changes to -1
            continue;
        int tempVar = check[i];
        while (tempVar != 1) {
            if (tempVar % 2 == 0)
                tempVar = tempVar / 2;
            else
                tempVar = ( 3 * tempVar + 1 ) / 2;
            for (int j = 0; j < n; j++){
                if (check[j] == tempVar){
                    check[j] = -1;
                    break;
                }
            }
        }
    }
    
    sort (check, 0, n - 1);
    int i = 0;
    while (i < n & check[i + 1] != -1){
        printf("%d ", check[i]);
        i++;
    }
    if (check[i] != -1 && i < n)
        printf("%d\n", check[i]);
    
    return 0;
}
