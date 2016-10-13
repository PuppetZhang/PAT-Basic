#include <iostream>

int check (int no){
    if (no == 1){
        return 0;
    }
    else {
        int flag = 1;
        for (int i = 2; i < no; i++){
            if (no % i == 0){
                flag = 0;
                break;
            }
        }
        if (flag == 1){
            return 1;
        }
        else{
            return 2;
        }
    }
}

int main() {
    int team[10005], num;
    //team -1 means this id isn't exist. -2 means checked. Number 0,1,2 follow the means of description
    for (int i = 0; i < 10005; i++){
        team[i] = -1;
    }
    scanf("%d", &num);
    for (int i = 1; i <= num; i++){
        int temp;
        scanf("%4d", &temp);
        team[temp] = check(i);
    }
    scanf("%d", &num);
    while(num --){
        int temp;
        scanf("%4d", &temp);
        printf("%04d: ", temp);
        switch (team[temp]){
            case -2: {printf("Checked\n"); break;}
            case -1: {printf("Are you kidding?\n"); break;}
            case 0: {printf("Mystery Award\n"); team[temp] = -2; break;}
            case 1: {printf("Minion\n"); team[temp] = -2; break;}
            case 2: {printf("Chocolate\n"); team[temp] = -2; break;}
            default: break;
        }
    }
    return 0;
}