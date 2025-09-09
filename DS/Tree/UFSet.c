//
// Created by zhouq on 25-8-16.
//
//���鼯

#define MAX_SIZE 10
#include "stdlib.h"
#include "stdio.h"

//����˫�ױ�ʾ��
int node[MAX_SIZE];


void initUFSet(int size){
  for (int i = 0; i < size; i++){
    //�ڵ�Ϊ����˵���ڵ�Ϊ���ڵ㣬��ʼ���нڵ㶼Ϊ���ڵ�
    //ֵ�ľ���ֵ�������ĸ߶ȣ���ʼ���ĸ߶ȶ�Ϊ1
    //�����¼������Ϊ����ֵ��ԭ������Find()�����ή������
    node[i] = -1;
  }
}

int Find(int x){
  if (node[x] <0 ) return x;
  //������·���ϵ����нڵ�ָ����ڵ㣬��߲���Ч��
  //���鼯�Ĳ���Ч���������й�
  return node[x] = Find(node[x]);
  // return  Find(node[x]);
}

void UnionByHeight(int x,int y){
  //�����ߺϲ�
  int rootx = Find(x);
  int rooty = Find(y);
  if (rootx != rooty){
    //�Ѱ������ϲ����ߵ�����
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
  //�����Ĵ�С�ϲ�
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
  printf("˫�ױ�ʾ������:\n");
  printf("����: ");
  for (int i = 0; i < MAX_SIZE; i++) {
    printf("%2d ", i);
  }
  printf("\nֵ:  ");
  for (int i = 0; i < MAX_SIZE; i++) {
    printf("%2d ", node[i]);
  }
  printf("\n\n");
}

void unionTest() {
  initUFSet(10);
  printf("��ʼ���鼯:\n");
  printUFSet();

  printf("------�ϲ�%d��%d------\n",1,2);
  UnionByHeight(1, 2);
  printf("�ϲ��󲢲鼯:\n");
  printUFSet();

  printf("------�ϲ�%d��%d------\n",3,2);
  UnionByHeight(3, 2);
  printf("�ϲ��󲢲鼯:\n");
  printUFSet();

  printf("------�ϲ�%d��%d------\n",3,4);
  UnionByHeight(3, 4);
  printf("�ϲ��󲢲鼯:\n");
  printUFSet();

  printf("------�ϲ�%d��%d------\n",5,6);
  UnionByHeight(5, 6);
  printf("�ϲ��󲢲鼯:\n");
  printUFSet();

  printf("------�ϲ�%d��%d------\n",7,8);
  UnionByHeight(7, 8);
  printf("�ϲ��󲢲鼯:\n");
  printUFSet();

  printf("------�ϲ�%d��%d------\n",9,0);
  UnionByHeight(9, 0);
  printf("�ϲ��󲢲鼯:\n");
  printUFSet();

  printf("------�ϲ�%d��%d------\n",9,7);
  UnionByHeight(9, 7);
  printf("�ϲ��󲢲鼯:\n");
  printUFSet();

  printf("------�ϲ�%d��%d------\n",7,6);
  UnionByHeight(7, 6);
  printf("�ϲ��󲢲鼯:\n");
  printUFSet();

  printf("------�ϲ�%d��%d------\n",6,4);
  UnionByHeight(6, 4);
  printf("�ϲ��󲢲鼯:\n");
  printUFSet();

  printf("------�ϲ�%d��%d------\n",3,2);
  UnionByHeight(3, 2);
  printf("�ϲ��󲢲鼯:\n");
  printUFSet();
}

void findTest() {
  const int arr[] = {8,2,8,2,2,6,8,8,-3,0};
  for (int i = 0;i<10;i++) {
    node[i] = arr[i];
  }
  printf("��ʼ����\n");
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