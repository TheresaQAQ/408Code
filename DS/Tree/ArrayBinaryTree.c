//
// Created by zhouq on 25-8-13.
//
#define MAX_SIZE 1000
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

typedef struct ArrayBinaryTreeNode{
  int data;
  bool isEmpty;
}ArrayBinaryTreeNode;

void initArrayBinaryTreeNode(ArrayBinaryTreeNode node[],int length) {
  for (int i = 0; i < length; i++) {
    node[i].isEmpty = true;
  }
}

bool isEmpty(ArrayBinaryTreeNode node[],int index,int length) {
  if (index<1 || index>=length) return true;
  return node[index].isEmpty;
}

int findFather(ArrayBinaryTreeNode node[],int index,int length) {
  if (index==1) return -1;
  index = index/2;
  if (isEmpty(node,index,length)) return -1;
  return index;
}

int leftChild(ArrayBinaryTreeNode node[],int index,int length) {
  index = index*2;
  if (isEmpty(node,index,length)) return -1;
  return index;
}

int rightChild(ArrayBinaryTreeNode node[],int index,int length){
  index = index*2+1;
  if (isEmpty(node,index,length)) return -1;
  return index;
}

void visitNode(ArrayBinaryTreeNode node[],int index,int length) {
  if (isEmpty(node,index,length)) return;
  printf("%d\t",node[index].data);
}

void ArrayBinaryTreeLDR(ArrayBinaryTreeNode *tree,int index,int length) {
  //中序遍历
  if (isEmpty(tree,index,length)) return;
  ArrayBinaryTreeLDR(tree,leftChild(tree,index,length),length);
  visitNode(tree,index,length);
  ArrayBinaryTreeLDR(tree,rightChild(tree,index,length),length);
}

void ArrayBinaryTreeDLR(ArrayBinaryTreeNode *tree,int index,int length) {
  if (isEmpty(tree,index,length)) return;
  visitNode(tree,index,length);
  ArrayBinaryTreeDLR(tree,leftChild(tree,index,length),length);
  ArrayBinaryTreeDLR(tree,rightChild(tree,index,length),length);
}

void ArrayBinaryTreeLRD(ArrayBinaryTreeNode *tree,int index,int length) {
  if (isEmpty(tree,index,length)) return;
  ArrayBinaryTreeLRD(tree,leftChild(tree,index,length),length);
  ArrayBinaryTreeLRD(tree,rightChild(tree,index,length),length);
  visitNode(tree,index,length);
}