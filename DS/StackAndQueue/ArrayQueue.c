//
// Created by zhouq on 25-8-12.
//
//队列的数组实现
#define MAX_SIZE 10
#include "stdlib.h"

typedef struct ArrayQueue{
  int data[MAX_SIZE];
  int front,rear;//front指向队头，rear指向队尾的下一个位置
}ArrayQueue;

ArrayQueue* initArrayQueue(){
  ArrayQueue* queue = malloc(sizeof(ArrayQueue));
  queue->front = 0;
  queue->rear = 0;
  return queue;
}

int isEmpty(ArrayQueue* queue){
  if(queue->front == queue->rear) return 1;
  return 0;
}

int isFull(ArrayQueue* queue){
  //牺牲一个位置用于判断是否队满
  if ((queue->rear+1)%MAX_SIZE == queue->front) return 1;
  return 0;
}

int getSize(ArrayQueue* queue){
  return (queue->rear - queue->front + MAX_SIZE)%MAX_SIZE;
}

int enqueue(ArrayQueue* queue, int data){
  if(isFull(queue)) return 0;
  queue->data[queue->rear] = data;
  queue->rear = (queue->rear+1)%MAX_SIZE;
  return 1;
}

int dequeue(ArrayQueue* queue, int* data){
  if(isEmpty(queue)) return 0;
  *data = queue->data[queue->front];
  queue->front = (queue->front+1)%MAX_SIZE;
  return 1;
}

int getHead(ArrayQueue* queue, int* data){
  if(isEmpty(queue)) return 0;
  *data = queue->data[queue->front];
  return 1;
}