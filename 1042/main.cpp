#include <iostream>

int main() {
    int num[30] = {0};
    char temp;
    while(scanf("%c", &temp) != EOF){
        if (temp <= 'Z' && temp >= 'A'){
            num[temp - 'A'] ++;
        }
        else if (temp <= 'z' && temp >= 'a'){
            num[temp - 'a'] ++;
        }
    }

    int max = 0;
    for (int i = 1; i < 25; i++){
        if (num[max] < num[i])
            max = i;
    }
    printf("%c %d\n", 'a' + max, num[max]);
    return 0;
}