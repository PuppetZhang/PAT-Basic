#include <iostream>
#include <string.h>
int main() {
    char wrongButton[50];
    int ascii[255] = {1}; //ascii[i] = 0 means it's broke
    for (int i = 0; i < 255; i++)
        ascii[i] = 1;
    char input[100005];
    gets(wrongButton);
    int lenWrongButton = strlen(wrongButton);
    for (int i = 0; i < lenWrongButton; i++){
        ascii[wrongButton[i]] = 0;
        if (wrongButton[i] >= 'A' && wrongButton[i] <= 'Z'){
            ascii[wrongButton[i] + 'a' - 'A'] = 0;
        }
    }

    scanf("%s", &input);
    int lenInput = strlen(input);


    for (int i = 0; i < lenInput; i++){
        if (input[i] <= 'Z' && input[i] >= 'A'){
            if (ascii[input[i]] == 1 && ascii['+'] == 1){
                printf("%c", input[i]);
            }
        }
        else {
            if (ascii[input[i]] == 1){
                printf("%c", input[i]);
            }
        }
    }
    printf("\n");
    return 0;
}

//输入中第一行可能有空格
