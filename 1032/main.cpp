#include <iostream>

int main() {
    int score[100005] = {0};
    int num;
    scanf("%d", &num);
    int no, tscore;
    int max = 0;
    score[0] = -1;
    while(num--){
        scanf("%d %d", &no, &tscore);
        score[no] += tscore;
        max = score[no] > score[max] ? no : max;
    }
    printf("%d %d\n", max, score[max]);
    return 0;
}