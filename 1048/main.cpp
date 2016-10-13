#include <stdio.h>
#include <string.h>

int main() {
    char inputa[105];
    char inputb[105];
    scanf("%s %s", &inputa, &inputb);
    int len2 = strlen(inputb);
    int len1 = strlen(inputa);
    int max = len2 > len1 ? len2 : len1;
    char output[105] = {'\0'};
    for (int a = len1 - 1, b = len2 - 1, i = 1; i <= max; a--, b--, i++){
        int key = 0, out, cleartext = 0;
        if (a >= 0)
            key = inputa[a] - '0';
        if (b >= 0)
            cleartext = inputb[b] - '0';
        if (i % 2 == 1) {
            out = (cleartext + key) % 13;
        }
        else {
            out = (cleartext - key);
            out = out < 0 ? out + 10 : out;
        }

        if (out < 10)
            output[max - i] = out + '0';
        else if (out == 10){
            output[max - i] = 'J';
        }
        else if (out == 11){
            output[max - i] = 'Q';
        }
        else if (out == 12){
            output[max - i] = 'K';
        }
    }
//    for (int i = 0; i < len2; i++)
        printf("%s", output);
    return 0;
}