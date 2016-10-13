#include <stdio.h>

int main() {
    int n, d;
    float e;
    scanf("%d %f %d", &n, &e, &d);
    int empty = 0, mayempty = 0, notempty = 0;
    for (int i = 0; i < n; i++){
        int observedays, count = 0;
        scanf ("%d", &observedays);
        float use;
        for (int j = 0; j < observedays; j++){
            scanf("%f", &use);
            if (use < e){
                count ++;
            }
        }
        if (count > observedays / 2){
            if (observedays > d){
                empty ++;
            }
            else {
                mayempty ++;
            }
        }
        else {
            notempty++;
        }
    }
    printf("%.1f%% ", mayempty * 100.0 / (n * 1.0));
    printf("%.1f%%\n", empty * 100.0 / (n * 1.0));

}