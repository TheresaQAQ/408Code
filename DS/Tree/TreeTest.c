//
// Created by zhouq on 25-8-13.
//
#include "ArrayBinaryTree.c"

int main(){
  ArrayBinaryTreeNode tree[8];
  initArrayBinaryTreeNode(tree,8);

  for (int i = 1; i < 8; i++) {
    tree[i].data = i;
    tree[i].isEmpty = false;
  }
  printf("\n�������\n");
  ArrayBinaryTreeLDR(tree,1,8);
  printf("\n�������\n");
  ArrayBinaryTreeDLR(tree,1,8);
  printf("\n�������\n");
  ArrayBinaryTreeLRD(tree,1,8);



  return 0;
  }