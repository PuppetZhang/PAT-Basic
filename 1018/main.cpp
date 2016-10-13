#include <iostream>

int check(char a, char b){
    if (a == 'C' && b == 'J')
        return 1;
    else if (a == 'C' && b == 'B')
        return -1;
    else if (a == 'J' && b == 'B')
        return 1;
    else if (a == 'J' && b == 'C')
        return -1;
    else if (a == 'B' && b == 'C')
        return 1;
    else if (a == 'B' && b == 'J')
        return -1;
    else
        return 0;
}

char nmax(int b, int j, int c){
    char out;
    if (b >= c && b >= j) {
        out = 'B';
    }
    else if (c > b && c >= j) {
        out = 'C';
    }
    else if (j > b && j > c) {
        out = 'J';
    }
    return out;
}

int main() {
    int n;
    scanf("%d", &n);
    char stra[5], strb[5];
    char gesturea, gestureb;
    int awin = 0, alose = 0, adraw = 0;
    int acw = 0, abw = 0, ajw = 0, bcw = 0, bbw = 0, bjw = 0;
    for (int i = 0; i < n; i++){
        scanf("%s %s", &stra, &strb);
        gesturea = stra[0];
        gestureb = strb[0];
        if (gesturea == gestureb) {
            adraw++;
        }
        else{
            int result = check(gesturea, gestureb);
            if (result == 1) {
                awin ++;
                if (gesturea == 'J')
                    ajw ++;
                else if (gesturea == 'C')
                    acw ++;
                else if (gesturea == 'B')
                    abw ++;
            }
            else if (result == -1){
                alose ++;
                if (gestureb == 'J')
                    bjw ++;
                else if (gestureb == 'C')
                    bcw ++;
                else if (gestureb == 'B')
                    bbw ++;
            }
            else
                printf("??");
        }
    }
    printf("%d %d %d\n", awin, adraw, alose);
    printf("%d %d %d\n", n - awin - adraw, adraw, n - alose - adraw);
    gesturea = nmax(abw, ajw, acw);
    gestureb = nmax(bbw, bjw, bcw);
    printf("%c %c\n", gesturea, gestureb);
    return 0;
}