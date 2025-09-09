//
// Created by zhouq on 25-8-14.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

//树的双亲表示法
typedef struct PTreeNode {
  int data;
  int parent;
}PTreeNode;

typedef struct PTree {
  PTreeNode node[MAX_SIZE];
  unsigned int size;
}Ptree;

Ptree* initTree(unsigned int size,int parant[]) {
  Ptree *tree = (Ptree*)malloc(sizeof(Ptree));
  tree->size = size;
  for (int i = 0; i < size; i++) {
    tree->node[i].data = i;
    tree->node[i].parent = parant[i];
  }
  for (int i = size; i < MAX_SIZE; i++) {
    tree->node[i].parent = -1;
    tree->node[i].data = -1;
  }
  return tree;
}