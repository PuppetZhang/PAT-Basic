#include <stdio.h>

int fbs(int a, int b){
    return a > b ? a - b : b - a;
}

void qsort(int *num, int left, int right){
    int key = num[left], start = left, end = right;
    if (left >= right){
        return ;
    }
    while (start < end){
        while (start < end && key >= num[end]){
            end --;
        }
        num[start] = num[end];
        while (start < end && key <= num[start]) {
            start ++;
        }
        num[end] = num[start];
    }

    num[start] = key;

    qsort(num, left, start - 1);
    qsort(num, start + 1, right);
}

int main() {
    int left = 1, right = 2, up = 3, down = 4;
    int N, num[10005], out[10005], m, n;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &num[i]);
    }
    if (N == 1){
        printf("%d\n", num[0]);
    }
    else {
        int min = N + 1;
        for (int i = 1; i <= N / 2; i++) {
            if (N % i == 0 && fbs(N / i, i) < min) {
                m = N / i > i ? N / i : i;
                n = N / i < i ? N / i : i;
                min = fbs(N / i, i);
            }
        }
        qsort(num, 0, N - 1);
//    for (int i = 0; i < N; i++){
//        printf("%d ", num[i]);
//    }
//    printf("\n");
        int line = 0, list = 0;//loc which location should be place
        int dirc = 2;//determine left = 1, right = 2, up = 3, down = 4
        int leftedge = 0, rightedge = n - 1, upedge = 1, downedge = m - 1;
        for (int i = 0; i < N; i++) {
            out[list * n + line] = num[i];

            //follow code make sure how to move
            if (dirc == left) {
                if (line == leftedge) {
                    dirc = up;
                    leftedge++;
                    list--;
                } else {
                    line--;
                }
            } else if (dirc == right) {
                if (line == rightedge) {
                    dirc = down;
                    rightedge--;
                    list++;
                } else {
                    line++;
                }
            } else if (dirc == up) {
                if (list == upedge) {
                    dirc = right;
                    upedge++;
                    line++;
                } else {
                    list--;
                }
            } else if (dirc == down) {
                if (list == downedge) {
                    dirc = left;
                    downedge--;
                    line--;
                } else {
                    list++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", out[i * n + j]);
                if (j != n - 1) {
                    printf(" ");
                }
            }
            if (i != m - 1) {
                printf("\n");
            }
        }
    }
}