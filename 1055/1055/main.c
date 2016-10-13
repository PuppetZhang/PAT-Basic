//
//  main.c
//  1055
//
//  Created by 摆线木偶 on 16/8/4.
//  Copyright © 2016年 摆线木偶. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

struct node{
    char name[10];
    int length;
}stu[10003];

bool check (struct node i, struct node j){
    if(i.length < j.length)
        return true;
    else if (i.length > j.length)
        return false;
    else{
        int len = strlen(i.name) > strlen(j.name) ? strlen(j.name) : strlen(i.name);
        for (int k = 0; k < len; k++){
            if (i.name[k] > j.name[k])
                return true;
            else if (i.name[k] < j.name[k])
                return false;
        }
        /*
         work of following code
         it means if there are two people:
         "amy 160" and "am 160"
         the result of sort is am is taller than amy
         */
        if (strlen(i.name) < strlen(j.name))
            return false;
        else
            return true;
    }
}

void sort(int left, int right){
    if (left >= right)
        return;
    struct node tempstu = stu[left];
    int i = left, j = right;
    
    while (i < j){
        
        while (i < j && check(stu[j], tempstu)){
            j --;
        }
        stu[i] = stu[j];
        while (i < j && check(tempstu, stu[i])){
            i ++;
        }
        stu[j] = stu[i];
    }
    stu[i] = tempstu;
    sort (left, i - 1);
    sort (i + 1, right);
    
    
}

int main(int argc, const char * argv[]) {
    int pnum, lnum;
    scanf("%d %d", &pnum, &lnum);
    for (int i = 0; i < pnum; i++){
        scanf("%s %d", stu[i].name, &stu[i].length);
    }
    sort(0, pnum - 1);
    
//    
//        for (int i = 0; i < pnum; i++){
//            printf("%s %d\n", stu[i].name, stu[i].length);
//        }
    
    
    int order[11][10003], eachnum = pnum / lnum;
    int lastnum = pnum - eachnum * (lnum - 1);
//
//    for (int i = 0; i < pnum; i++){
        int midloc, halfnum, oeflag = -1, pnow = 0;
        for (int j = 0; j <lnum; j++){
            if (j == 0){
                halfnum = midloc = lastnum / 2; // notice :4 people, the tallest people should in no.3, but in array it's no.2,so there is no need to extra plus one
                oeflag = lastnum % 2;
            }
            else{
                halfnum = midloc = eachnum / 2;
                oeflag = eachnum % 2;
            }
            order[j][midloc] = pnow ++;
            for (int k = 1; k <= halfnum; k++){
                order[j][midloc - k] = pnow ++;
                if (oeflag == 0 && k == halfnum)
                    continue;
                else{
                    order[j][midloc + k] = pnow ++;
                }
            }
//        }
    }
    for (int j = 0; j < lnum; j++){
        int t = j == 0 ? lastnum : eachnum;
        for (int i = 0; i < t; i++){
            if (i != t - 1){
                printf("%s ", stu[order[j][i]].name);
            }
            else {
                printf("%s\n", stu[order[j][i]].name);
            }
        }
       // printf("\n");
    }
 
    
    return 0;
}
