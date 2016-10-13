#include <iostream>
struct node{
    int data;
    int next;
    int pre;
}l[100005];
struct node start;
struct node end;

void rev(int startAdd, int endAdd){
    int pre = l[startAdd].pre;
    int next = l[endAdd].next;

    int p = startAdd;
    while (p != next){
        int temp;
        temp = l[p].next;
        l[p].next = l[p].pre;
        l[p].pre = temp;
        p = l[p].pre;
    }



    ((pre == -2) ? start.next : l[pre].next) = endAdd;
    ((next == -1) ? end.pre : l[next].pre)= startAdd;

    l[startAdd].next = next;
    l[endAdd].pre = pre;

}

int main() {

    int startAdd, datanum, revnum;
    scanf("%d %d %d", &startAdd, &datanum, &revnum);
    start.next = startAdd;
    int temp = datanum;
    while (temp--){
        int address, data, next;
        scanf("%d %d %d", &address, &data, &next);
        l[address].data = data;
        l[address].next = next;
    }

    int address = startAdd, preaddress = -2;//-2 means start, -1 means end;
    l[address].pre = preaddress;
    while (address != -1){
        l[address].pre = preaddress;
//        printf("%05d %05d %d %05d\n", link[address].pre, address, link[address].data, link[address].next);
        preaddress = address;
        if (l[address].next == -1)
            end.pre = address;
        address = l[address].next;

    }


    int p, startAddress, endAddress, count;
    p = startAddress = startAdd;
    count = 1;
    while (p != -1){
        if (count % revnum == 0){
            endAddress = p;
            rev (startAddress, endAddress);
            p = startAddress;
            startAddress = l[startAddress].next;
        }
        count ++;
        p = l[p].next;
    }


    p = start.next;
    while (l[p].next != -1){
        printf("%05d %d %05d\n", p, l[p].data, l[p].next);
        p = l[p].next;
    }
    printf("%05d %d -1\n", p, l[p].data);




    return 0;
}