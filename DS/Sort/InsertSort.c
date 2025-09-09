//
// Created by zhouq on 25-8-26.
//
void InsertSort(int array[],int length){
  for (int i = 2; i <= length; i++){
    for (int j = i; j > 0; j--){
      int temp = array[j];
      if (temp < array[j - 1]){
        array[j] = array[j - 1];
      }else {
        array[j] = temp;
        break;
      }
    }
  }
}