#include <stdio.h>

struct node {
    char no[10];
    int virtuepoint;
    int talentpoint;
    int allpoint;
    int level;
}stu[100005];
//     level = 1; //talent >= h && virtue >= h. List from high to low
//     level = 2;  //vir >= h > tal
//     level = 3;  //h > vir > tal
//     level = 4; //other stu who talent >= l && virtue >= l;


void qsort(int left, int right){
    struct node key = stu[left];
    int start = left, end =right;
    if (left >= right)
        return;
    while (start < end){
        while (start < end && key.level <= stu[end].level){
            end --;
        }
        stu[start] = stu[end];
        while (start < end && key.level >= stu[start].level){
            start ++;
        }
        stu[end] = stu[start];
    }
    stu[start] = key;
    qsort(left, start - 1);
    qsort(start + 1, right);
}

int checkno(struct node s1, struct node s2){
    for (int i = 0; i < 8; i++)
    {
        if (s1.no[i] != s2.no[i]){
            return s1.no[i] < s2.no[i] ? 1 : 0;
        }
    }
    return 1;
}

int check(struct node s1, struct node s2){


    if(s1.level != s2.level)
        return s1.level < s2.level ? 1 : 0;

    //first sort by talentpoint+virtuepoint from high to low
    else if (s1.allpoint != s2.allpoint)
        return s1.allpoint > s2.allpoint ? 1: 0;


        //if talentpoint+virtuepoint is same sort by their virtuepoint from high to low
    else if (s1.virtuepoint != s2.virtuepoint)
        return s1.virtuepoint > s2.virtuepoint ? 1 : 0;

    else

        //else if their talentpoint+virtuepoint and virtuepoint are both same sort by their stuno from high to low
        return checkno(s1, s2);

}

//sort by their all point from high to low
void newqsort(int left, int right){
    struct node key = stu[left];
    int start = left, end =right;
    if (left >= right)
        return;
    while (start < end){
        // check's return should key >= stu[end]
        while (start < end && check(key, stu[end])){
            end --;
        }
        stu[start] = stu[end];
        while (start < end && check(stu[start], key)){
            start ++;
        }
        stu[end] = stu[start];
    }
    stu[start] = key;
    newqsort(left, start - 1);
    newqsort(start + 1, right);
}


int main() {
    int n, l, h;
    scanf ("%d %d %d", &n, &l, &h);
    if (n != 0) {
        struct node tempstu;
        int num = 0;//talent >= l && virtue >= l
        for (int i = 0; i < n; i++) {
            scanf("%s %d %d", &tempstu.no, &tempstu.virtuepoint, &tempstu.talentpoint);
            if (tempstu.virtuepoint >= l && tempstu.talentpoint >= l) {
                if (tempstu.talentpoint >= h && tempstu.virtuepoint >= h)
                    tempstu.level = 1;
                else if (tempstu.talentpoint < h && tempstu.virtuepoint >= h)
                    tempstu.level = 2;
                else if (tempstu.talentpoint <= tempstu.virtuepoint && tempstu.talentpoint < h &&
                         tempstu.virtuepoint < h)
                    tempstu.level = 3;
                else
                    tempstu.level = 4;

                stu[num] = tempstu;
                stu[num].allpoint = stu[num].talentpoint + stu[num].virtuepoint;
                num++;
            }
        }

        printf("%d\n", num);
        if (num != 0) {
//            qsort(0, num - 1);
//            int startend[5][2] = {-1};
//            startend[stu[0].level][0] = 0;
//            for (int i = 1; i < num; i++) {
//                if (i != 0 && stu[i - 1].level != stu[i].level) {
//                    startend[stu[i - 1].level][1] = i - 1;
//                    startend[stu[i].level][0] = i;
//                }
//            }
//            startend[stu[num - 1].level][1] = num - 1;
//
//            for (int i = 1; i < 5; i++) {
//                if (startend[i][0] != -1)
//                    newqsort(startend[i][0], startend[i][1]);
//            }
            newqsort(0, num - 1);

            for (int i = 0; i < num; i++) {
                printf("%s %d %d\n", stu[i].no, stu[i].virtuepoint, stu[i].talentpoint);
            }

        }
    }
    return 0;
}



//1、开始时使用两次快排(:第x类快排,再各类内部快排)导致超时, 合成一次后不超时
//2、答案错误: 没有注意到(德才分均低于H，但是德分   "不低于"    才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序) 不低于是 <= 不是 <