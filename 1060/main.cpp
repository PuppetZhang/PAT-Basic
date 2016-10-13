#include <iostream>
int exercise[100005];

void q_sort(int left, int right){
    if (left >= right)
        return;
    else {
        int start, end, key;
        start = left;
        end = right;
        key = exercise[left];
        while (start < end){
            while (start < end && exercise[end] <= key){
                end --;
            }
            exercise[start] = exercise[end];
            while (start < end && exercise[start] >= key){
                start ++;
            }
            exercise[end] = exercise[start];
        }
        exercise[start] = key;
        q_sort(left, start - 1);
        q_sort(start + 1, right);
    }
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0.0; i < num; i++){
        scanf("%d", &exercise[i]);
    }
    q_sort(0, num - 1);

    int max = 0;
    for (int i = 0; i < num; i++){
        if (exercise[i] > i + 1){
            max = i + 1;
        }
        else {
            break;
        }
    }
    printf("%d\n", max);
    return 0;
}