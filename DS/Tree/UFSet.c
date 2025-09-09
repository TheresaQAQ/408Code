//
// Created by zhouq on 25-8-16.
//
//并查集

#define MAX_SIZE 10
#include "stdlib.h"
#include "stdio.h"

//树的双亲表示法
int node[MAX_SIZE];


void initUFSet(int size){
  for (int i = 0; i < size; i++){
    //节点为负数说明节点为根节点，初始所有节点都为根节点
    //值的绝对值代表数的高度，初始树的高度都为1
    //这里记录的树高为估计值，原因在于Find()操作会降低树高
    node[i] = -1;
  }
}

int Find(int x){
  if (node[x] <0 ) return x;
  //将查找路径上的所有节点指向根节点，提高查找效率
  //并查集的查找效率与树高有关
  return node[x] = Find(node[x]);
  // return  Find(node[x]);
}

void UnionByHeight(int x,int y){
  //按树高合并
  int rootx = Find(x);
  int rooty = Find(y);
  if (rootx != rooty){
    //把矮的树合并到高的树上
    if (node[rootx] > node[rooty]){
      node[rootx] = rooty;
    }else if (node[rootx] < node[rooty]){
      node[rooty] = rootx;
    }else{
      node[rootx] = rooty;
      node[rooty]--;
    }
  }
}

void UnionBySize(int x,int y){
  //按树的大小合并
  int rootx = Find(x);
  int rooty = Find(y);
  if (rootx != rooty){
    if (node[rootx] > node[rooty]){
      node[rootx] = rooty;
      node[rooty]+= node[rootx];
    }else {
      node[rooty] = rootx;
      node[rootx]+= node[rooty];
    }
  }
}

void printUFSet() {
  printf("双亲表示法数组:\n");
  printf("索引: ");
  for (int i = 0; i < MAX_SIZE; i++) {
    printf("%2d ", i);
  }
  printf("\n值:  ");
  for (int i = 0; i < MAX_SIZE; i++) {
    printf("%2d ", node[i]);
  }
  printf("\n\n");
}

void unionTest() {
  initUFSet(10);
  printf("初始并查集:\n");
  printUFSet();

  printf("------合并%d和%d------\n",1,2);
  UnionByHeight(1, 2);
  printf("合并后并查集:\n");
  printUFSet();

  printf("------合并%d和%d------\n",3,2);
  UnionByHeight(3, 2);
  printf("合并后并查集:\n");
  printUFSet();

  printf("------合并%d和%d------\n",3,4);
  UnionByHeight(3, 4);
  printf("合并后并查集:\n");
  printUFSet();

  printf("------合并%d和%d------\n",5,6);
  UnionByHeight(5, 6);
  printf("合并后并查集:\n");
  printUFSet();

  printf("------合并%d和%d------\n",7,8);
  UnionByHeight(7, 8);
  printf("合并后并查集:\n");
  printUFSet();

  printf("------合并%d和%d------\n",9,0);
  UnionByHeight(9, 0);
  printf("合并后并查集:\n");
  printUFSet();

  printf("------合并%d和%d------\n",9,7);
  UnionByHeight(9, 7);
  printf("合并后并查集:\n");
  printUFSet();

  printf("------合并%d和%d------\n",7,6);
  UnionByHeight(7, 6);
  printf("合并后并查集:\n");
  printUFSet();

  printf("------合并%d和%d------\n",6,4);
  UnionByHeight(6, 4);
  printf("合并后并查集:\n");
  printUFSet();

  printf("------合并%d和%d------\n",3,2);
  UnionByHeight(3, 2);
  printf("合并后并查集:\n");
  printUFSet();
}

void findTest() {
  const int arr[] = {8,2,8,2,2,6,8,8,-3,0};
  for (int i = 0;i<10;i++) {
    node[i] = arr[i];
  }
  printf("初始化：\n");
  printUFSet();
  int find[] = {1,3,4,5,9};
  for (int i = 0;i<5;i++) {
    printf("Find(%d) ",find[i]);
    Find(find[i]);
    printUFSet();
  }

}

int main(){
  findTest();
}