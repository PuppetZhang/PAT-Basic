#include <iostream>

int main() {
    char input;
    int num[10] = {0};
    while(scanf("%c", &input) != EOF){
        int n = input - '0';
        num[n] ++;
    }
    for (int i = 0; i < 10; i++){
        if (num[i] != 0){
            printf("%d:%d\n", i, num[i]);
        }
    }
    return 0;
}