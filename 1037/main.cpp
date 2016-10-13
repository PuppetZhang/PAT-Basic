#include <iostream>
struct money{
    int Galleon;
    int Sickle;
    int Knut;
};

int cmp(struct money shouldPay, struct money payed){
    if (shouldPay.Galleon == payed.Galleon && shouldPay.Sickle == payed.Sickle && shouldPay.Knut == payed.Knut) {
        return 0;
    }
    else if (shouldPay.Galleon > payed.Galleon || (shouldPay.Galleon == payed.Galleon && shouldPay.Sickle > payed.Sickle) || (shouldPay.Galleon == payed.Galleon && shouldPay.Sickle == payed.Sickle && shouldPay.Knut > payed.Knut)){
        return -1;
    }
    else{
        return 1;
    }
}

int main() {
    struct money shouldPay, payed;
    scanf("%d.%d.%d", &shouldPay.Galleon, &shouldPay.Sickle, &shouldPay.Knut);
    scanf("%d.%d.%d", &payed.Galleon, &payed.Sickle, &payed.Knut);
    int flag = cmp(shouldPay, payed);
    struct money tmp;
    if (flag == 0) {
        printf("0.0.0\n");
        return 0;
    }
    else if (flag == -1) {
        printf("-");
        tmp = shouldPay;
        shouldPay = payed;
        payed = tmp;
    }
    int det;
    det = payed.Knut - shouldPay.Knut;
    tmp.Knut = det >= 0 ? det : det + 29;
    payed.Sickle = det >= 0 ? payed.Sickle : payed.Sickle - 1;

    det = payed.Sickle - shouldPay.Sickle;
    tmp.Sickle = det >= 0 ? det : det + 17;
    payed.Galleon = det >= 0 ? payed.Galleon : payed.Galleon - 1;

    det = payed.Galleon - shouldPay.Galleon;
    tmp.Galleon = det;

    printf("%d.%d.%d\n", tmp.Galleon, tmp.Sickle, tmp.Knut);
    return 0;
}