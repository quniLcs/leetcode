#include<stdio.h>

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize){
    *returnSize = 0;

    int *result = (int*)malloc(sizeof(int) * matrixSize * (*matrixColSize));
    int layer = 0;
    int matrixCurRowSize = matrixSize;
    int matrixCurColSize = *matrixColSize;

    while (matrixCurRowSize > 0 && matrixCurColSize > 0){
        for (int index = 0; index < matrixCurColSize; index++){
            result[*returnSize] = matrix[layer][layer + index];
            (*returnSize)++;
        }
        for (int index = 1; index < matrixCurRowSize; index++){
            result[*returnSize] = matrix[layer + index][layer + matrixCurColSize - 1];
            (*returnSize)++;
        }
        if (matrixCurRowSize > 1 && matrixCurColSize > 1){
            for (int index = matrixCurColSize - 2; index >= 0; index--){
                result[*returnSize] = matrix[layer + matrixCurRowSize - 1][layer + index];
                (*returnSize)++;
            }
            for (int index = matrixCurRowSize - 2; index > 0; index--){
                result[*returnSize] = matrix[layer + index][layer];
                (*returnSize)++;
            }
        }
        layer++;
        matrixCurRowSize -= 2;
        matrixCurColSize -= 2;
    }

    return result;
}

void main(){
    int matrixSize = 2;
    int matrixColSize = 3;

    int **matrix = (int**)malloc(sizeof(int*) * matrixSize);
    for (int indexRow = 0; indexRow < matrixSize; indexRow++){
        matrix[indexRow] = (int*)malloc(sizeof(int) * matrixColSize);
        for (int indexCol = 0; indexCol < matrixColSize; indexCol++){
            matrix[indexRow][indexCol] = matrixColSize * indexRow + indexCol + 1;
        }
    }

    int returnSize;
    int *result = spiralOrder(matrix, matrixSize, &matrixColSize, &returnSize);

    for (int index = 0; index < returnSize; index++){
        printf("%d\t", result[index]);
    }
    printf("\n");
}