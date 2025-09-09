//
// Created by zhouq on 25-8-14.
//
//孩子兄弟表示法
#include "stdlib.h"
#include "stdio.h"

typedef struct CSNode{
  int data;
  struct CSNode *fistChild,*nextSibling;
}CSNode,*CSTree;