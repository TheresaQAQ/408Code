//
// Created by zhouq on 25-8-11.
//
//栈的双链表实现
#define MAX_SIZE 100
#include "stdlib.h"
#include "stdio.h"

typedef struct Node{
  int data;
  struct Node *pre,*next;
}Node;

typedef struct DoubleLinkStack{
  int size;
  Node *head,*rear;
}DoubleLinkStack;

DoubleLinkStack *initDoubleLinkStack() {
  DoubleLinkStack *stack = malloc(sizeof(DoubleLinkStack));
  if (stack == NULL) return NULL;
  stack->head= NULL;
  stack->rear = NULL;
  stack->size = 0;
  return stack;
}

void destroyDoubleLinkStack(DoubleLinkStack *stack) {
  free(stack);
}

int isFull(DoubleLinkStack *stack) {
  if (stack->size == MAX_SIZE) return 1;
  return 0;
}

int isEmpty(DoubleLinkStack *stack) {
  if (stack->size == 0) return 1;
  return 0;
}

int pop(DoubleLinkStack *stack,int *data) {
  if (isEmpty(stack)) return 0;
  stack->size--;
  Node *temp = stack->head;
  *data = temp->data;
  stack->head = temp->pre;
  free(temp);
  return 1;
}

int push(DoubleLinkStack *stack,int data) {
  if (isFull(stack)) return 0;
  stack->size++;
  Node *temp = malloc(sizeof(Node));
  temp->data = data;
  temp->pre = stack->head;
  stack->head = temp;
  return 1;
}
