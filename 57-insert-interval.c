#include<stdbool.h>
#include<assert.h>

int max(int a, int b){
    return a > b ? a : b;
}

int **insert(int **intervals, int intervalsSize, int *intervalsColSize, int *newInterval, int newIntervalSize, int *returnSize, int **returnColumnSizes){
    assert(newIntervalSize == 2);
    for (int index = 0; index < intervalsSize; index++){
        assert(intervalsColSize[index] == 2);
    }

    int **result = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (intervalsSize + 1));
    *returnSize = 0;

    bool inserted = false;
    for (int index = 0; index < intervalsSize; index++){
        if (!inserted && newInterval[0] <= intervals[index][0]){
            result[*returnSize] = (int*)malloc(sizeof(int) * 2);
            result[*returnSize][0] = newInterval[0];
            result[*returnSize][1] = newInterval[1];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
            inserted = true;
        }
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
        if (!inserted && newInterval[0] <= result[*returnSize - 1][1]){
            result[*returnSize - 1][1] = max(result[*returnSize - 1][1], newInterval[1]);
            inserted = true;
        }
    }
    if (!inserted){
        result[*returnSize] = (int*)malloc(sizeof(int) * 2);
        result[*returnSize][0] = newInterval[0];
        result[*returnSize][1] = newInterval[1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        inserted = true;
    }

    return result;
}


// another solution with reference to
// https://leetcode.cn/problems/insert-interval/solution/cha-ru-qu-jian-by-leetcode-solution/
/*
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    assert(newIntervalSize == 2);
    for (int index = 0; index < intervalsSize; index++){
        assert(intervalsColSize[index] == 2);
    }
    
    int **result = malloc(sizeof(int*) * (intervalsSize + 1));
    *returnColumnSizes = malloc(sizeof(int*) * (intervalsSize + 1));
    *returnSize = 0;

    int left = newInterval[0];
    int right = newInterval[1];
    bool inserted = false;
    for (int index = 0; index < intervalsSize; index++){
        if (intervals[index][1] < left){
            result[*returnSize] = (int*)malloc(sizeof(int) * 2);
            result[*returnSize][0] = intervals[index][0];
            result[*returnSize][1] = intervals[index][1];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
        else if (intervals[index][0] > right){
            if (!inserted){
                result[*returnSize] = (int*)malloc(sizeof(int) * 2);
                result[*returnSize][0] = left;
                result[*returnSize][1] = right;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
                inserted = true;
            }
            result[*returnSize] = (int*)malloc(sizeof(int) * 2);
            result[*returnSize][0] = intervals[index][0];
            result[*returnSize][1] = intervals[index][1];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
        else{
            left = left < intervals[index][0] ? left : intervals[index][0];
            right = right > intervals[index][1] ? right : intervals[index][1];
        }
    }
    if (!inserted){
        result[*returnSize] = (int*)malloc(sizeof(int) * 2);
        result[*returnSize][0] = left;
        result[*returnSize][1] = right;
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        inserted = true;
    }

    return result;
}
*/