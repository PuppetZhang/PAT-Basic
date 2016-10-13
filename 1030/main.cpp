#include <iostream>
double array[100005];

void q_sort(int start, int end){
    if (start >= end)
        return;
    int left = start, right = end;
    double mid = array[start];
    while (left < right){
        while (left < right && array[right] >= mid)
            right --;
        array[left] = array[right];
        while (left < right && array[left] <= mid)
            left ++;
        array[right] = array[left];
    }
    array[left] = mid;
    q_sort(start, left - 1);
    q_sort(left + 1, end);
}

int main() {
    double n, p;
    scanf("%lf %lf", &n, &p);
    for (int i = 0; i < n; i++){
        scanf("%lf", &array[i]);
    }
    q_sort(0, n - 1);//1. you need to be able to write a quicksort function by you own
//    qsort();//2.you need to be able to use the qsort function provided by c++
    int max = 0;

    int start = 0, end = 0;
    while (start < n){
        while (end < n && (array[start] * p >= array[end])){
            end ++;
            int dis = end - start;
            max = max > dis ? max : dis;
        }
        start ++;
    }

    printf("%d\n", max);

    return 0;
}