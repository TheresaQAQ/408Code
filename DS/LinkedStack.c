//
// Created by zhouq on 2025/3/15.
//
#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

typedef struct LinkedStack {
    Node *top;
    int size;
} LinkedStack;

void initLinkedStack(LinkedStack *stack) {
    stack->size = 0;
    stack->top = NULL;
}

int pushLinkedStack(LinkedStack *stack, ElemType value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return -1;
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    return 0;
}

ElemType popLinkedStack(LinkedStack *stack) {
    Node *poppedNode = stack->top;
    stack->top = poppedNode->next;
    ElemType poppedDate = poppedNode->data;
    free(poppedNode);
    stack->size--;
    return poppedDate;
}

ElemType getLinkedStackTop(LinkedStack *stack) {
    return stack->top->data;
}


int main() {
    printf("Hello World!\n");
    LinkedStack stack;
    initLinkedStack(&stack);
    for (int i = 0; i < 5; i++) {
        pushLinkedStack(&stack, i);
    }

    while (stack.size > 0) {
        ElemType data = popLinkedStack(&stack);
        printf("%d  \n", data);
    }
    printf("\n");
    return 0;
}