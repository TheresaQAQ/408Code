//
// Created by zhouq on 25-8-26.
//

#include "InsertSort.c"
#include "stdio.h"

void printArray(int arr[], int size){
  for(int i = 0; i < size; i++) printf("%d ",arr[i]);
}

int main(){
  int array[] = {23,72,45,21,56,32,42,12,43,65};
  int length = 10;

  InsertSort(array, length);
  printArray(array, length);

  return 0;
}