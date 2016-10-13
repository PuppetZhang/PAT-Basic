#include <iostream>
struct people {
    char name[7];
    int year;
    int month;
    int day;
};

int check(int year, int month, int day){
    if (year > 2014 || (year == 2014 && month > 9) || (year == 2014 && month == 9 && day > 6)){
        return 0;
    }
    else if (year < 1814 || (year == 1814 && month < 9) || (year == 1814 && month == 9 && day < 6)){
        return 0;
    }
    else
        return 1;
}

int cmp(struct people small, struct people big){
    if (small.year < big.year || (small.year == big.year && small.month < big.month) || (small.year == big.year && small.month == big.month && small.day < big.day)){
        return 0;
    }
    else
        return 1;
}

int main() {
    int num;
    scanf("%d", &num);
    char date[10];

    int validnum = 0;
    struct people young, old;

    young.year = 1814;
    young.month = 9;
    young.day = 5;

    old.year = 2014;
    old.month = 9;
    old.day = 7;



    struct people temp;
    while(num--){
        scanf("%s %s", &temp.name, date);
        temp.year = temp.month = temp.day = 0;
        for (int j = 0; j < 4; j++){
            temp.year = temp.year * 10 + date[j] - '0';
        }
        for (int j = 0; j < 2; j++){
            temp.month = temp.month * 10 + date[j + 5] - '0';
            temp.day = temp.day * 10 + date[j + 8] - '0';
        }

        if (check(temp.year, temp.month, temp.day)){
            validnum++;
            if (cmp(temp, young)){
                young = temp;
            }
            if (cmp(old, temp)){
                old = temp;
            }
        }
    }
    if (validnum > 0)
        printf("%d %s %s\n", validnum, old.name, young.name);
    else
        printf("%d\n", validnum);

    return 0;
}