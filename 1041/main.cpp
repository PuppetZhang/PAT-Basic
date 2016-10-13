#include <iostream>

struct info{
    char id[15];
    int seat1;
    int seat2;
};

int main() {
    int num;
    scanf("%d", &num);
    struct info peo[1005];
    struct info temp;
    while (num--){
        scanf("%s %d %d", &temp.id, &temp.seat1, &temp.seat2);
        peo[temp.seat1] = temp;
    }
    int checknum;
    scanf("%d", &checknum);
    while (checknum --){
        int beCheck;
        scanf("%d", &beCheck);
        printf("%s %d\n", peo[beCheck].id, peo[beCheck].seat2);
    }
    return 0;
}