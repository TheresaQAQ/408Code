//
// Created by zhouq on 2025/3/15.
//

#define MAX_SIZE 100
#include "stdio.h"
#include "stdlib.h"


typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *pre;
} Node;

typedef struct SingleSingleLinkStack {
    Node *top;
    int size;
} SingleLinkStack;

SingleLinkStack *initSingleLinkStack() {
    SingleLinkStack *stack = malloc(sizeof(SingleLinkStack));
    if (stack == NULL) return NULL;
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void destroySingleLinkStack(SingleLinkStack *stack) {
    free(stack);
}

int isEmpty(SingleLinkStack *stack) {
    if (stack->size == 0) return 1;
    return 0;
}

int isFull(SingleLinkStack *stack) {
    if (stack->size == MAX_SIZE) return 1;
    return 0;
}

int push(SingleLinkStack *stack, ElemType elem) {
    if (isFull(stack)) return 0;
    Node *newNode = malloc(sizeof(Node));
    newNode->data = elem;
    newNode->pre = stack->top;
    stack->top = newNode;
    stack->size++;
    return 1;
}

int pop(SingleLinkStack *stack, ElemType *elem) {
    if (isEmpty(stack)) return 0;
    Node *top = stack->top;
    *elem = top->data;
    stack->top = top->pre;
    free(top);
    stack->size--;
    return 1;
}


