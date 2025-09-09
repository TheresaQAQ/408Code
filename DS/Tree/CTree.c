//
// Created by zhouq on 25-8-14.
//
//孩子表示法
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

typedef struct CTreeNode{
  int data;
  struct CTreeNode *next;
}CTreeNode;

typedef struct CTree{
  CTreeNode node[MAX_SIZE];
  int size;
}CTree;

CTree* initCtree(){
  CTree* ctree = (CTree*)malloc(sizeof(CTree));
  for (int i = 0; i < MAX_SIZE; i++) {
    CTreeNode* node = (CTreeNode*)malloc(sizeof(CTreeNode));
    node->next = NULL;
    ctree->node[i] = *node;
  }
  return ctree;
}