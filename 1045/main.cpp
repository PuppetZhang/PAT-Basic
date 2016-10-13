#include <iostream>

int main() {
    int n, flag[100005], pnum;
    long int num[100005], min, max;
    scanf("%d", &n);
    pnum = n;
    for (int i = 0; i < n; i++){
        flag[i] = 1;
        scanf("%ld", &num[i]);
        //for each num[i] which smaller than it's left flag[0] change to 0;
        if (i == 0)
            max = num[i];
        else {
            if (num[i] < max) {
                flag[i] = 0;
                pnum --;
            }
            else {
                max = num[i];
            }
        }
    }
    for (int i = n - 1; i >= 0; i--){
        if (i == n - 1)
            min = num[i];
        else {
            if (num[i] > min) {
                if (flag[i] != 0)
                    pnum --;
                flag[i] = 0;
            }
            else {
                min = num[i];
            }
        }
    }
    printf("%d\n", pnum);
    if(pnum != 0) {
        for (int i = 0; i < n; i++) {
            if (flag[i]) {
                if (i != 0)
                    printf(" %ld", num[i]);
                else
                    printf("%ld", num[i]);
            }
        }
    }
    return 0;
}