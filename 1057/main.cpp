#include <iostream>

int main() {
    char input;
    double count;
    count = 0.0;
    while (scanf("%c", &input) && input != '\n'){
        if(input <= 'Z' && input >= 'A'){
            input = input - 'A' + 'a';
        }
        if(input <= 'z' && input >= 'a'){
            count += (double) (input - 'a' + 1);
        }
    }

    if (count == 0.0)
        printf("0 0");
    else {
        double dec;
        dec = 1.0;
        while (dec * 2 <= count) {
            dec = dec * 2;
        }

        double countOne, countZero;
        countOne = countZero = 0.0;
        while (dec >= 1) {
            if (count >= dec) {
                countOne++;
                count -= dec;
            } else {
                countZero++;
            }
            dec = dec / 2;
        }
        printf("%.0lf %.0lf", countZero, countOne);
    }
    return 0;
}

//() 时应输出0 0