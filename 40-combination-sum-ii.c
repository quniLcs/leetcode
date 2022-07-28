#include<stdio.h>

int **conbinationSumRecursive(int *candidatesTable, int candidatesLargest, int target, int *returnSize, int **returnColumnSizes){
    if (candidatesLargest == 0){
        *returnColumnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    else{
        int **result = (int**)malloc(sizeof(int*) * 150);
        *returnColumnSizes = (int*)malloc(sizeof(int) * 150);
        memset(*returnColumnSizes, 0, sizeof(int) * 150);
        *returnSize = 0;

        for (int largest = 0; largest <= candidatesTable[candidatesLargest]; largest++){
            int remain = target - largest * candidatesLargest;
            if (remain > 0){
                int tempReturnSize;
                int *tempReturnColumnSizes;
                int **tempResult = conbinationSumRecursive(candidatesTable, candidatesLargest - 1, remain, &tempReturnSize, &tempReturnColumnSizes);
                for (int index = 0; index < tempReturnSize; index++){
                    result[*returnSize] = (int*)malloc(sizeof(int) * (largest + tempReturnColumnSizes[index]));
                    for (int time = 0; time < largest; time++){
                        result[*returnSize][(*returnColumnSizes)[*returnSize]] = candidatesLargest;
                        (*returnColumnSizes)[*returnSize]++;
                    }
                    for (int tempIndex = 0; tempIndex < tempReturnColumnSizes[index]; tempIndex++){
                        result[*returnSize][(*returnColumnSizes)[*returnSize]] = tempResult[index][tempIndex];
                        (*returnColumnSizes)[*returnSize]++;
                    }
                    (*returnSize)++;
                }
            }
            else if (remain == 0){
                result[*returnSize] = (int*)malloc(sizeof(int) * largest);
                for (int time = 0; time < largest; time++){
                    result[*returnSize][(*returnColumnSizes)[*returnSize]] = candidatesLargest;
                    (*returnColumnSizes)[*returnSize]++;
                }
                (*returnSize)++;
            }
        }

        return result;
    }
}

int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes){
    int candidatesTable[51] = {0};
    for (int index = 0; index < candidatesSize; index++){
        candidatesTable[candidates[index]]++;
    }

    return conbinationSumRecursive(candidatesTable, 50, target, returnSize, returnColumnSizes);
}