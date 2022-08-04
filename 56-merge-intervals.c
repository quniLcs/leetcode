#include<stdio.h>
#include<assert.h>

int compare(const void *a, const void *b){
    return **(int**)a - **(int**)b;
}

int max(int a, int b){
    return a > b ? a : b;
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes){
    for (int index = 0; index < intervalsSize; index++){
        assert(intervalsColSize[index] == 2);
    }

    int **result = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);
    *returnSize = 0;

    qsort((void*)intervals, (size_t)intervalsSize, sizeof(int*), compare);
    for (int index = 0; index < intervalsSize; index++){
        if (*returnSize == 0 || intervals[index][0] > result[*returnSize - 1][1]){
            result[*returnSize] = (int*)malloc(sizeof(int) * 2);
            result[*returnSize][0] = intervals[index][0];
            result[*returnSize][1] = intervals[index][1];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
        else{
            result[*returnSize - 1][1] = max(result[*returnSize - 1][1], intervals[index][1]);
        }
    }

    return result;
}

void main(){
    int intervalsSize = 4;
    int *intervalsColSize = (int*)malloc(sizeof(int) * intervalsSize);
    for (int index = 0; index < intervalsSize; index++){
        intervalsColSize[index] = 2;
    }

    int **intervals = (int**)malloc(sizeof(int*) * intervalsSize);
    for (int index = 0; index < intervalsSize; index++){
        intervals[index] = (int*)malloc(sizeof(int) * 2);
    }
    intervals[0][0] = 15;
    intervals[0][1] = 18;
    intervals[1][0] = 1;
    intervals[1][1] = 3;
    intervals[2][0] = 2;
    intervals[2][1] = 6;
    intervals[3][0] = 8;
    intervals[3][1] = 10;

    int returnSize;
    int* returnColumnSizes;
    int** result = merge(intervals, intervalsSize, intervalsColSize, &returnSize, &returnColumnSizes);
}