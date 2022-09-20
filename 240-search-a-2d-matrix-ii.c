#include<stdbool.h>
#include<assert.h>

bool searchMatrixRecursively(int **matrix, int top, int bottom, int left, int right, int target){
    int row = (top + bottom) / 2;
    int col = (left + right) / 2;

    if (matrix[row][col] == target){
        return true;
    }
    else{
        if (matrix[row][col] < target && row + 1 <= bottom && searchMatrixRecursively(matrix, row + 1, bottom, col, right, target)) return true;
        if (matrix[row][col] > target && top <= row - 1 && searchMatrixRecursively(matrix, top, row - 1, left, col, target)) return true;
        if (col + 1 <= right && searchMatrixRecursively(matrix, top, row, col + 1, right, target)) return true;
        if (left <= col - 1 && searchMatrixRecursively(matrix, row, bottom, left, col - 1, target)) return true;
        return false;
    }
}

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target){
    int m = matrixSize;
    int n = matrixColSize[0];
    for (int i = 1; i < m; i += 1){
        assert(matrixColSize[i] == n);
    }

    return searchMatrixRecursively(matrix, 0, m - 1, 0, n - 1, target);
}