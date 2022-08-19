int **generate(int numRows, int *returnSize, int **returnColumnSizes){
    int **result = (int**)malloc(sizeof(int*) * numRows);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    *returnSize = numRows;

    for (int i = 0; i < numRows; i += 1){
        (*returnColumnSizes)[i] = i + 1;
        result[i] = (int*)malloc(sizeof(int) * (i + 1));
        result[i][0] = 1;
        result[i][i] = 1;
        for (int j = 1; j < i; j += 1){
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    return result;
}