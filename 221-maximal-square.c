#include<assert.h>

int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}

int maximalSquare(char **matrix, int matrixSize, int *matrixColSize){
    int m = matrixSize;
    int n = matrixColSize[0];
    for (int i = 1; i < m; i += 1){
        assert(matrixColSize[i] == n);
    }

    int **ones = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i += 1){
        ones[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j += 1){
            if (matrix[i][j] == '0') ones[i][j] = 0; 
            else ones[i][j] = j == 0 ? 1 : (ones[i][j - 1] + 1); 
        }
    }

    int a = 0;
    for (int i = 0; i < m; i += 1){
        for (int j = 0; j < n; j += 1){
            if (matrix[i][j] == '1'){
                int w = ones[i][j];
                for (int k = 0; k < w && i + k < m; k += 1){
                    w = min(w, ones[i + k][j]);
                    a = max(a, min(w, k + 1));
                }
            }
        }
    }
    return a * a;
}