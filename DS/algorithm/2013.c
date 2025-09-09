//
// Created by zhouq on 25-9-9.
//
#include "stdio.h"

int solution(const int A[], const int n) {
  int num[n];
  for (int i = 0; i < n; i++) num[i] = 0;
  for (int i = 0; i < n; i++) num[A[i]]++;


  for (int i = 0; i < n; i++) {
    if (num[i] > n/2 ) return i;
  }
  return -1;
}

int main(){
  const int A[] = {0,5,5,3,5,7,5,5};
  const int B[] = {0,5,5,3,5,1,5,7};
  printf("%d\n", solution(A, 8));
  printf("%d\n", solution(B, 8));

  return 0;
}