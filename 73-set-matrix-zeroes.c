#include<stdbool.h>
#include<assert.h>

void setZeroes(int **matrix, int matrixSize, int *matrixColSize){
    int m = matrixSize;
    int n = matrixColSize[0];
    for (int i = 1; i < m; i++){
        assert(matrixColSize[i] == n);
    }

    bool *row = (bool*)malloc(sizeof(bool) * m);
    bool *col = (bool*)malloc(sizeof(bool) * n);
    memset(row, false, sizeof(bool) * m);
    memset(col, false, sizeof(bool) * n);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == 0){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }
}