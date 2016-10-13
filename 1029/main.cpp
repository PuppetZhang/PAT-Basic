#include <iostream>
#include <string.h>

int main() {
    int ascii[200] = {0};
    char input[100] = {'\0'}, output[100] = {'\0'};
    scanf("%s %s", &input, &output);
    int lenIn = strlen(input), indexIn = 0, indexOut = 0;

    for (indexIn = 0; indexIn < lenIn; indexIn ++){
        if (input[indexIn] != output[indexOut]){
            if (input[indexIn] <= 'z' && input[indexIn] >= 'a'){
                input[indexIn] = input[indexIn] + 'A' - 'a';
            }
            if (ascii[input[indexIn]] == 0)
                printf("%c", input[indexIn]);
            ascii[input[indexIn]] = 1;
        }
        else {
            indexOut ++;
        }
    }



    return 0;
}