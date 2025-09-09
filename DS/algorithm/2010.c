//
// Created by zhouq on 25-9-7.
//

#include "stdio.h"
void solution(int R[],int n,int p){
  //长度为n的数组R，循环左移p个单位
  int temp[n];
  for (int i=0;i<n;i++) temp[i]=R[i];
  for (int i=0;i<n;i++){
    int j = (i+p+n) % n;
    R[i]=temp[j];
  }
}

int main(){
  int R[] = {0,1,2,3,4,5,6,7,8,9};
  int n = 10;
  solution(R,n,2);
  for (int i=0;i<n;i++){
    printf("%d ",R[i]);
  }
}
