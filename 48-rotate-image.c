// almost directly copied from
// https://leetcode.cn/problems/rotate-image/solution/xuan-zhuan-tu-xiang-by-leetcode-solution-vu3m/

/*
void rotate(int **matrix, int matrixSize, int *matrixColSize){
    for (int i = 0; i < matrixSize / 2; i++){
        for (int j = 0; j < (matrixSize + 1) / 2; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - j - 1][i];
            matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
            matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
            matrix[j][matrixSize - i - 1] = temp;
        }
    }
}
*/

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize / 2; i++){
        for (int j = 0; j < matrixSize; j++){
            swap(&matrix[i][j], &matrix[matrixSize - i - 1][j]);
        }
    }

    for (int i = 0; i < matrixSize; i++){
        for (int j = 0; j < i; j++){
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}