#include <iostream>
struct node {
    float stroe;
    float value;
    float pervalue;
}mooncake[1003];

void qsort(int left, int right){
    if (left >= right)
        return;
    int start = left, end =right, key = mooncake[start].pervalue;
    struct node tempmc = mooncake[left];
    while (start < end){
        while(mooncake[end].pervalue <= key && start < end)
            end --;
        mooncake[start] = mooncake[end];
        while(mooncake[start].pervalue >= key && start < end)
            start ++;
        mooncake[end] = mooncake[start];
    }
    mooncake[start] = tempmc;
    qsort(left, start - 1);
    qsort(start + 1, right);
}

int main() {
    int n, need;

    scanf("%d %d", &n, &need);
    for (int i = 0; i < n; i++){
        scanf("%f", &mooncake[i].stroe);
    }
    for (int i = 0; i < n; i++){
        scanf("%f", &mooncake[i].value);
        mooncake[i].pervalue =  mooncake[i].value / mooncake[i].stroe;
    }
    qsort(0, n - 1);
    int i = 0;
    float earn = 0.0;
    while (need > 0 && i < n){
        if (mooncake[i].stroe <= need){
            need -= mooncake[i].stroe;
            earn += mooncake[i].value;
        }
        else{
            earn += mooncake[i].pervalue * (float) need;
            need -= mooncake[i].stroe;
        }
        i++;
    }
    printf("%.2f\n", earn);
    return 0;
}