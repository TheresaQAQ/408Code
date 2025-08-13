//
// Created by zhouq on 25-8-12.
//
#include "stdio.h"
// #include "ArrayQueue.c"
#include "SingleLinkQueue.c"
int main() {
    // ArrayQueue *queue = initArrayQueue();
    SingleLinkQueue *queue = initSingleLinkQueue();
    for (int i = 1; i <= 15; i++) {
        if (enqueue(queue, i)) printf("%d enqueue\n", i);
        if (isFull(queue)) printf("queue is full,size=%d\n", getSize(queue));
    }

    for (int i = 1; i <= 15; i++) {
        int j = 0;
        if (dequeue(queue, &j)) printf("%d dequeue\n", i);
        if (isEmpty(queue)) printf("queue is empty\n");
    }
    return 0;
}
