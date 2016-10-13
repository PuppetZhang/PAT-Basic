#include <iostream>

int main() {
    double num;
    int scorenum[101] = {0};
    int temp;
    scanf("%lf", &num);
    while (num --){

        scanf("%d", &temp);
        scorenum[temp] ++;
    }
    scanf("%lf", &num);
    while (num --){
        scanf("%d", &temp);
        if (num != 0)
            printf("%d ", scorenum[temp]);
        else
            printf("%d\n", scorenum[temp]);
    }
    return 0;
}