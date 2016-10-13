#include <stdio.h>

int main() {
    int score[1005] = {-1};
    int n;
    scanf("%d", &n);
    char input[15]; //max 1000-10 100
    while (n--){
        int sinScore;
        scanf("%s %d", &input, &sinScore);
        int temp = 0;
        for (int i = 0; input[i] != '-'; i++){
            temp = temp * 10 + input[i] - '0';
        }
        score[temp] += sinScore;
    }
    int max = 1;
    for (int i = 2; i < 1001; i++){
        if (score[i] > score[max])
            max = i;
    }
    printf("%d %d", max, score[max]);
    return 0;
}