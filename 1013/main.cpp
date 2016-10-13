#include <iostream>
#include <math.h>
int main() {
    int pn, pm;
    int oddNum[10004];
    scanf("%d %d", &pn, &pm);
    int oddn = 2;
    oddNum[1] = 2;
    for (int i = 2; oddn <= pm; i++){
        int flag = 0;
        for (int j = 2; j < sqrt(i) + 1; j++){
            if (i % j == 0){
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            oddNum[oddn++] = i;
            printf("%d\n", i);
        }

    }
    for (int i = pn, j = 0; i <= pm; i++, j++){
        j = j % 10;
            if (j != 9 && i != pm)
                printf("%d ", oddNum[i]);
            else
                printf("%d\n", oddNum[i]);


    }
    return 0;
}