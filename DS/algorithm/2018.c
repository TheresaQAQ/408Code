#include "stdio.h"
#include "../Sort/QuicklySort.c"

int solution(int A[], const int n) {
    QuicklySort(A, 0, n - 1);
    int result = 1;
    for (int i = 0; i < n; i++) {
        if (A[i] ==result) result++;
        else if (A[i] > result) return result;
    }
    return result;
}

int main() {
    int A[] = {-5,3,2,3};
    int B[] = {1,2,3};
    printf("%d\n",solution(A, 4));
    printf("%d\n",solution(B, 3));
    return 0;
}
