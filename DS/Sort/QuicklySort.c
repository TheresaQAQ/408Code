//
// Created by zhouq on 25-5-16.
//
#include "stdio.h"

int Partition(int array[], int low, int high) {
    int temp = array[low]; //第一个元素作为基准

    while (low < high) {
        //从右向左找到第一个小于基准的元素，将其移到左边
        while (low < high && array[high] >= temp)--high;
        array[low] = array[high];

        //从左向右找到第一个大于基准的元素，将其移到右边
        while (low < high && array[low] <= temp) ++low;
        array[high] = array[low];
    }
    //重复这个过程直到左右指针相遇，赤此时所有比基准元素大的在low右边，比基准元素小的在low左边  ！！注意此时low=high

    array[low] = temp;
    return low;
}

void QuicklySort(int array[], int low, int high) {
    if (low < high) {
        int index = Partition(array, low, high);
        QuicklySort(array, low, index - 1);
        QuicklySort(array, index + 1, high);
    }
}

// void main() {
//     int arr[] = {14, 15, 42, 15, 65, 41, 88, 24};
//
//     const int arr_length = sizeof(arr) / sizeof(arr[0]);
//     printf("Original array elements: \n");
//     for (int i = 0; i < arr_length; i++) {
//         printf("\t%d", arr[i]);
//     }
//     QuicklySort(arr, 0, arr_length - 1);
//     printf("\n array length:%d \n", arr_length);
//     printf("Sorted array elements: \n");
//     for (int i = 0; i < arr_length; i++) {
//         printf("\t%d", arr[i]);
//     }
// }
