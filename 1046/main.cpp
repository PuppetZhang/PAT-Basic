#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int aact, asaid, bact, bsaid;
    int acount = 0, bcount = 0;
    while (n--){
        scanf("%d %d %d %d", &asaid, &aact, &bsaid, &bact);
        if (aact == asaid + bsaid && aact != bact)
            bcount ++;
        if (bact == bsaid + asaid && bact != aact)
            acount ++;
    }
    printf("%d %d\n", acount, bcount);
    return 0;
}