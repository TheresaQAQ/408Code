//
// Created by zhouq on 25-8-11.
//

#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStack {
    int stack[MAX_SIZE];
    int top;
} ArrayStack;

ArrayStack *initArrayStack() {
    ArrayStack *stack = malloc(sizeof(ArrayStack));
    if (stack == NULL) return NULL;
    stack->top = -1;
    return stack;
}

void destroyArrayStack(ArrayStack *stack) {
    free(stack);
}

int isFull(ArrayStack *stack) {
    if (stack->top == MAX_SIZE - 1) return 1;
    return 0;
}

int isEmpty(ArrayStack *stack) {
    if (stack->top == -1) return 1;
    return 0;
}

int pop(ArrayStack *stack, int *n) {
    if (isEmpty(stack) == 1) return 0;
    *n = stack->stack[stack->top];
    stack->top--;
    return 1;
}

int push(ArrayStack *stack, int n) {
    if (isFull(stack) == 1) return 0;
    stack->top++;
    stack->stack[stack->top] = n;
    return 1;
}

int getTop(ArrayStack *stack, int *n) {
    if (isEmpty(stack) == 1) return 0;
    *n = stack->stack[stack->top];
    return 1;
}