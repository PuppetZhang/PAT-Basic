#include <stdio.h>
#include <string.h>

char highdig[13][5] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
char lowdig[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

void erathToMars(char input[]){
    int high, low, len = strlen(input);
    int num = 0;
    for (int i = 0; i < len; i++){
        num = num * 10 + input[i] - '0';
    }

    high = num / 13;
    low = num % 13;
    if (high != 0) {
        if (low == 0) {
            printf("%s\n", highdig[high]);
        }
        else{
            printf("%s %s\n", highdig[high], lowdig[low]);
        }
    }
    else
        printf("%s\n", lowdig[low]);

}


void marsToEarth(char input[]){
    int len = strlen(input);
    int count = -1, num = 0;
    char low[10] = {'\0'}, high[10] = {'\0'};


    for (int i = 0; i < len; i++){
        if (input[i] == ' '){
            count = i;
            for (int j = 0; j < i; j++)
                high[j] = input[j];
            for (int j = i + 1; j < len; j++)
                low[j - i - 1] = input[j];
            break;
        }
    }
    if (count == -1){
        num = -1;
        for (int i = 0; i < 13; i++){
            if(!strcmp(lowdig[i], input)){
                num = i;
            }

        }
        if(num != -1)
            printf("%d\n", num);
        else {
            for (int i = 1; i < 13; i++) {
                if (!strcmp(highdig[i], input)) {
                    printf("%d\n", i * 13);
                    break;
                }
            }
        }
    }
    else{
        for (int i = 0; i < 13; i++){
            if(!strcmp(highdig[i], high)){
                num = i * 13;
            }
        }
        for (int i = 0; i < 13; i++){
            if(!strcmp(lowdig[i], low)){
                num = num + i;
            }
        }

        printf("%d\n", num);
    }
}


int main() {
    int n;
    char input[10] = {'\0'};
    char temp;
    scanf("%d", &n);
    scanf("%c", &temp);
    while(n--) {
        for (int j = 0; j < 10; j++)
            input[j] = '\0';
        int i = 0;
        while (scanf("%c", &temp) && temp != '\n') {
            input[i ++] = temp;
        }
        if (input[0] <= '9' && input[0] >= '0')
            erathToMars(input);
        else
            marsToEarth(input);
    }
    return 0;
}




// 数字26 输出为hel 不是hel tret
// 同理 输入hel 输出应为26