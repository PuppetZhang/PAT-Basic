#include <iostream>

struct option{
    int score;
    int optNum;
    int rightNum;
    int choice[5];
    int errNum;
};



int main() {
    char inputStr[2] = {'\0'};
    struct option options[105];
    int peoNum, optionNum;
    scanf("%d %d", &peoNum, &optionNum);
    for (int i = 0; i < optionNum; i++){
        scanf("%d %d %d ", &options[i].score, &options[i].optNum, &options[i].rightNum);
        options[i].errNum = 0;
        for (int j = 0; j < 5; j++){
            options[i].choice[j] = 0;
        }
        for (int j = 0; j < options[i].rightNum; j++){
            char tmp[2];
            scanf("%s", tmp);
            options[i].choice[tmp[0] - 'a'] = 1;
            if (i != options[i].rightNum - 1)
                scanf(" ");
        }
    }


    for (int i = 0; i < peoNum; i++){

        int optNum = 0;
        int errFlag = -1;
        int stuScore = 0;


        while (optNum != optionNum){
            scanf("%s", inputStr);
            errFlag = 1;
            int choiceNum = inputStr[1] - '0';
            for (int j = 0; j < choiceNum; j++){
                scanf("%s", inputStr);
                if (options[optNum].choice[inputStr[0] - 'a'] != 1){
                    errFlag = 0;
                }
            }
            if (choiceNum < options[optNum].rightNum)
                errFlag = 0;
            options[optNum].errNum += (errFlag == 0 ? 1 : 0);
            stuScore += (errFlag * options[optNum].score);
            optNum ++;
        }

        printf("%d\n", stuScore);
    }

    int max = 0;
    for (int i = 0; i < optionNum; i++){
        if (options[i].errNum > max){
            max = options[i].errNum;
        }
    }
    if (max == 0)
        printf("Too simple\n");
    else {
        printf("%d", max);
        for (int i = 0; i < optionNum; i++){
            if (options[i].errNum == max){
                printf(" %d", i + 1);
            }
        }
        printf("\n");
    }
    return 0;
}