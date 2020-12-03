#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
    //return *(int *)b - *(int *)a; 由大到小排序
}

int binSearch(int *num, int numSize, int left, int right, int key){
    if(left > right) return -1;
    int mid = left + (right - left) / 2;
    if(num[mid] * num[mid] == key){
        return mid;
    }
    if(num[mid] * num[mid] > key){
        return binSearch(num, numSize, left, mid - 1, key);
    }else{
        return binSearch(num, numSize, mid + 1, left, key);
    }
}

int judgeSquareSum(int *num, int numSize){
    qsort(num, numSize, sizeof(int), cmp);
    int count = 0;
    for(int i = 0; i < numSize - 1; i++){
        for(int j = i + 1; j < numSize; j++){
            int sqSum = num[i] * num[i] + num[j] * num[j];
            printf("[%d][%d]:sqSum = %d\n", i, j, sqSum);
            for(int k = 0; num[k] * num[k] <= sqSum && k < numSize; k++){
                int key = sqSum - num[k] * num[k];
                int a = binSearch(num, numSize, 0, numSize, key);
                printf("a: %d, k: %d\t", a, k);
                printf("key = %d\n", key);
                if(i != k && i != a && j != k && j != a && a != -1){
                    printf("i = %d\t", i);
                    printf("j = %d\t", j);
                    printf("k = %d\t", k);
                    printf("a = %d\n", a);
                    count++;
                }
            }
        }
    }
    return count;
}

int judgeSquareSum_fi(int *num, int numSize){
    qsort(num, numSize, sizeof(int), cmp);
    int count = 0;
    for(int i = 0; i < numSize - 1; i++){
        for(int j = i + 1; j < numSize; j++){
            int sqSum = num[i] * num[i] + num[j] * num[j];
            printf("[%d][%d]:sqSum = %d\n", i, j, sqSum);
        }
    }
    return count;
}

int main() {
    int num[] = {3, 4, 2, 0, 1, 5};
    int numSize = sizeof(num) / sizeof(int);
    // for(int i = 0; i < numSize; i++){
    //     printf("%d\t", num[i]);
    // }
    // putchar(10);
    // printf("sorted\n");
    // qsort(num, numSize, sizeof(int), cmp);
    // for(int i = 0; i < numSize; i++){
    //     printf("%d\t", num[i]);
    // }
    // putchar(10);
    int res = judgeSquareSum(num, numSize);
    printf("%d\n", res);
    return 0;
}