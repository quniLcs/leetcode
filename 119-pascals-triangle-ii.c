int *getRow(int rowIndex, int *returnSize){
    int *result = (int*)malloc(sizeof(int) * (rowIndex + 1));
    *returnSize = rowIndex + 1;

    for (int j = 0; j <= rowIndex; j += 1){
        result[j] = 1;
    }

    for (int i = 2; i <= rowIndex; i += 1){
        for (int j = i - 1; j > 0; j -= 1){
            result[j] += result[j - 1];
        }
    }

    return result;
}