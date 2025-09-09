//
// Created by zhouq on 25-8-13.
//
//32. 最长有效括号
//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号 子串 的长度。
//左右括号匹配，即每个左括号都有对应的右括号将其闭合的字符串是格式正确的，比如 "(()())"。
//
// Created by zhouq on 25-8-11.
//

#define MAX_SIZE 100000
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
int longestValidParentheses(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {

    }
}