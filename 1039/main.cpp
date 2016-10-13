#include <iostream>
#include "string.h"

int main() {
    char str1[1005], str2[1005];
    int len1, len2, count[71] = {0};
    scanf("%s", str1);
    scanf("%s", str2);
    len1 = strlen(str1);
    len2 = strlen(str2);

    int loc;
    for (int i = 0; i < len1; i++){
        if (str1[i] >= '0' && str1[i] <= '9'){
            loc = str1[i] - '0';
        }
        else if (str1[i] >= 'a' && str1[i] <= 'z'){
            loc = str1[i] - 'a' + 10;
        }
        else if (str1[i] >= 'A' && str1[i] <= 'Z'){
            loc = str1[i] - 'A' + 36;
        }
        count[loc] ++;
    }

    int flag = 0;
    for (int i = 0; i < len2; i++){
        if (str2[i] >= '0' && str2[i] <= '9'){
            loc = str2[i] - '0';
        }
        else if (str2[i] >= 'a' && str2[i] <= 'z'){
            loc = str2[i] - 'a' + 10;
        }
        else if (str2[i] >= 'A' && str2[i] <= 'Z'){
            loc = str2[i] - 'A' + 36;
        }

        if (count[loc] != 0){
            count[loc] --;
        }
        else {
            flag ++;
        }
    }

    if (flag == 0){
        printf("Yes %d\n", len1 - len2);
    }
    else {
        printf("No %d\n", flag);
    }

    return 0;
}