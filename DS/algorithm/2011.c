//
// Created by zhouq on 25-9-7.
//
#include "stdio.h"
int solution(int A[], int B[], int n){
    //求出两个等长升序序列的中位数
    int i=0,a=0,b=0,temp=0;
    while(i<n){
      if(A[a]>B[b]) {
        temp=B[b];
        b++;
      }
      else {
        temp=A[a];
        a++;
      }
      i++;
    }
    return temp;
}

int main(){
  int A[]={11,13,15,17,19};
  int B[]={2,4,6,8,20};
  int answer=solution(A,B,5);
  printf("%d",answer);
}