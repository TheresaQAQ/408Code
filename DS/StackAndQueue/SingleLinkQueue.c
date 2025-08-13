//
// Created by zhouq on 25-8-12.
//
#define MAX_SIZE 10
#include "stdlib.h"

typedef struct Node{
  int data;
  struct Node *next;
}Node;

typedef struct SingleLinkQueue{
  Node *front, *rear;
}SingleLinkQueue;

SingleLinkQueue *initSingleLinkQueue(){
  SingleLinkQueue *queue = (SingleLinkQueue *)malloc(sizeof(SingleLinkQueue));
  queue->front =queue->rear= malloc(sizeof(Node));
  return queue;
}

int isEmpty(SingleLinkQueue *queue){
  if (queue->front == queue->rear) return 1;
  return 0;
}

int getSize(SingleLinkQueue *queue){
  if (isEmpty(queue)) return 0;
  int n = 0;
  Node *temp = queue->front->next;
  while (temp != NULL) {
    temp = temp->next;
    n++;
  }
  return n;
}

int isFull(SingleLinkQueue *queue){
  if (getSize(queue) == MAX_SIZE) return 1;
  return 0;
}

int enqueue(SingleLinkQueue *queue, int data){
  if (isFull(queue)) return 0;
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  queue->rear->next = newNode;
  queue->rear = newNode;
  return 1;
}

int dequeue(SingleLinkQueue *queue,int *data){
  if (isEmpty(queue)) return 0;
  Node *dequeued = queue->front;
  *data = dequeued->data;
  queue->front = queue->front->next;
  free(dequeued);
  return 1;
}