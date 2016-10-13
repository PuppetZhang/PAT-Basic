#include <iostream>

int getmax(int n){
    int num[4], temp = n;
    for (int i = 0; i < 4; i++){
        num[i] = temp % 10;
        temp = temp / 10;
    }
    for (int i = 0; i < 4; i++){
        for (int j = i + 1; j < 4; j++)
            if (num[i] < num[j]){
                char temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
    }
    int max = 0;
    for (int i = 0; i < 4; i++){
        max = max * 10 + num[i];
    }
    return max;
}

int getmin(int n){
    int min = 0, temp = n;
    for (int i = 0; i < 4; i ++){
        min = min * 10 + temp % 10;
        temp = temp / 10;
    }
    return min;
}

int main() {
    int input;
    scanf("%d", &input);
    int max = 0, min = 0;
    max = getmax(input);
    min = getmin(max);

    int det = max - min;
    while (det != 0 && det != 6174){
        printf("%04d - %04d = %04d\n", max, min, det);
        max = getmax(det);
        min = getmin(max);
        det = max - min;
    }
    printf("%04d - %04d = %04d\n", max, min, det);
    return 0;
}