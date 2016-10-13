#include <stdio.h>

int print(int n, int besort[], int type){
    if(type == 1)
        printf("Insertion Sort\n");
    else
        printf("Merge Sort\n");
    for (int j = 0; j < n; j++) {
        if (j != n - 1) {
            printf("%d ", besort[j]);
        }
        else
            printf("%d\n", besort[j]);
    }
    return 1;
}

int eqcheck(int n, int besort[], int insort[]){
    int flag = 1;
    for (int i = 0; i < n; i++){
        if (besort[i] != insort[i]){
            flag = 0;
            break;
        }
    }
    return flag;
}

int insSort(int n, int besort[], int insort[]) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        int check = besort[i], temp = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (check < besort[j]) {
                temp = besort[j + 1];
                besort[j + 1] = besort[j];
                besort[j] = temp;
            }
            else
                break;
        }
/*
        printf("%d sort: ",i + 1);
        for (int j = 0; j < n; j++) {
            if (j == i)
                printf("|");
            if (j != n - 1) {
                printf("%d ", besort[j]);
            } else
                printf("%d\n", besort[j]);
        }*/
        if (result == 1){
            print(n, besort, 1);
            break;
        }
        result = eqcheck(n, besort, insort);

    }
    return 0;
}


int merSort(int n, int besort[], int insort[]) {
    int det = 1, result = 0;
    while (det < n){
        det = det * 2;
        for (int i = 0; i < n;){
            int j = i + det / 2;
            if (j >= n)
                break;
            int istart = i, iend = j, jstart = j, jend = j + det / 2 < n ? j + det / 2 : n;
            //将第二队列从第一个开始逐个插入
            for (int k = jstart; k < jend; k++){
                int t = k;
                while (t > istart){
                    if (besort[t] < besort[t - 1]){
                        int temp = besort[t];
                        besort[t] = besort[t - 1];
                        besort[t - 1] = temp;
                        t --;
                    }
                    else
                        break;
                }
            }
            i = jend;
        }
/*
        printf("%d sort: ",det);
        for (int j = 0; j < n; j++) {
            if (j % det == 0)
                printf("|");
            if (j != n - 1) {
                printf("%d ", besort[j]);
            } else
                printf("%d\n", besort[j]);
        }

*/
        if (result == 1) {
            print(n, besort, 2);
            break;
        }
        result = eqcheck(n, besort, insort);

    }
    return 0;
}

int main() {
    int n, besort[105], insort[105], mersort[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &besort[i]);
        mersort[i] = besort[i];
    }

    for (int i = 0; i < n; i++){
        scanf("%d", &insort[i]);
    }
    int result;
    insSort(n, besort, insort);
    merSort(n, mersort, insort);
    return 0;
}