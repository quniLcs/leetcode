#include<stdio.h>

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int **conbinationSumRecursive(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes){
    if (candidatesSize == 0){
        *returnColumnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    else{
        int **result = (int**)malloc(sizeof(int*) * 150);
        *returnColumnSizes = (int*)malloc(sizeof(int) * 150);
        memset(*returnColumnSizes, 0, sizeof(int) * 150);
        *returnSize = 0;

        for (int largest = 0; largest <= target / candidates[candidatesSize - 1]; largest++){
            int remain = target - largest * candidates[candidatesSize - 1];
            if (remain > 0){
                int tempReturnSize;
                int *tempReturnColumnSizes;
                int **tempResult = conbinationSumRecursive(candidates, candidatesSize - 1, remain, &tempReturnSize, &tempReturnColumnSizes);
                for (int index = 0; index < tempReturnSize; index++){
                    result[*returnSize] = (int*)malloc(sizeof(int) * (largest + tempReturnColumnSizes[index]));
                    for (int time = 0; time < largest; time++){
                        result[*returnSize][(*returnColumnSizes)[*returnSize]] = candidates[candidatesSize - 1];
                        (*returnColumnSizes)[*returnSize]++;
                    }
                    for (int tempIndex = 0; tempIndex < tempReturnColumnSizes[index]; tempIndex++){
                        result[*returnSize][(*returnColumnSizes)[*returnSize]] = tempResult[index][tempIndex];
                        (*returnColumnSizes)[*returnSize]++;
                    }
                    (*returnSize)++;
                }
            }
            else{  // remain == 0
                result[*returnSize] = (int*)malloc(sizeof(int) * largest);
                for (int time = 0; time < largest; time++){
                    result[*returnSize][(*returnColumnSizes)[*returnSize]] = candidates[candidatesSize - 1];
                    (*returnColumnSizes)[*returnSize]++;
                }
                (*returnSize)++;
            }
        }

        return result;
    }
}

int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes){
    qsort((void*)candidates, (size_t)candidatesSize, sizeof(int), compare);
    return conbinationSumRecursive(candidates, candidatesSize, target, returnSize, returnColumnSizes);
}

void main(){
    int candidates[4] = {2, 3, 6, 7};
    int returnSize;
    int *returnColumnSizes;
    int **result = combinationSum(candidates, 4, 7, &returnSize, &returnColumnSizes);

    for (int index = 0; index < returnSize; index++){
        for (int tempIndex = 0; tempIndex < returnColumnSizes[index]; tempIndex++){
            printf("%d\t", result[index][tempIndex]);
        }
        printf("\n");
    }
}