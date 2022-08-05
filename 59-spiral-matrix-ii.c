int **generateMatrix(int n, int *returnSize, int **returnColumnSizes){
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        (*returnColumnSizes)[i] = n;
    }

    int **result = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++){
        result[i] = (int*)malloc(sizeof(int) * n);
    }

    int currentOrder = 1;
    for (int layer = 0, currentSize = n; layer < n / 2; layer++, currentSize -= 2){
        for (int index = 0; index < currentSize; index++){
            result[layer][layer + index] = currentOrder;
            currentOrder++;
        }
        for (int index = 1; index < currentSize; index++){
            result[layer + index][layer + currentSize - 1] = currentOrder;
            currentOrder++;
        }
        for (int index = currentSize - 2; index >= 0; index--){
            result[layer + currentSize - 1][layer + index] = currentOrder;
            currentOrder++;
        }
        for (int index = currentSize - 2; index > 0; index--){
            result[layer + index][layer] = currentOrder;
            currentOrder++;
        }
    }
    if (n % 2){
        result[n / 2][n / 2] = currentOrder;
        currentOrder++;
    }

    return result;
}