#include <iostream>

int main() {
    int num;
    int val[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    scanf("%d", &num);

    int flag = 1;//flag = 1 means all pass, flag = 0 means there are some wrong.
    char id[17];
    while(num--){
        int tflag = 0;
        int sum = 0;
        scanf("%c", &id[0]);
        for (int i = 0; i < 17; i++){
            scanf("%c", &id[i]);
            if (id[i] > '9' || id[i] < '0') {
                tflag = 1;
            }
            sum += (id[i] - '0') * val[i];
        }
        char last;
        scanf("%c", &last);
        sum = sum % 11;
        if (last != M[sum]) {
            tflag = 1;
        }
        if (tflag == 1){
            flag = 0;
            for (int i = 0; i < 17; i++){
                printf("%c", id[i]);
            }
            printf("%c\n", last);
        }
    }
    if (flag == 1)
        printf("All passed\n");
    return 0;
}