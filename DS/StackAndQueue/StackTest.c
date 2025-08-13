//
// Created by zhouq on 25-8-11.
//
// #include "ArrayStack.c"
#include "SingleLinkStack.c"
void main() {
    SingleLinkStack *stack = initSingleLinkStack();
    if (stack == NULL) return ;
    for (int i = 0; i < 10; i++) {
        printf("pushed number is:%d\n", i);
        push(stack, i);
    }
    printf("---------------------------------\n");
    for (int i = 0; i < 10; i++) {
        int n = 0;
        if (pop(stack, &n) == 1) {
            printf("popped number is:%d\n", n);
        }
    }
    if (isEmpty(stack) == 1) printf("stack is empty\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        push(stack, i);
    }
    if (isFull(stack) == 1) printf("stack is full\n");

    destroySingleLinkStack(stack);
}