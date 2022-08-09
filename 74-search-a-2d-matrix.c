#include<stdbool.h>
#include<assert.h>

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target){
    int m = matrixSize;
    int n = matrixColSize[0];
    for (int i = 1; i < m; i++){
        assert(matrixColSize[i] == n);
    }

    int top = 0;
    int bottom = m - 1;
    while (top < bottom){
        int mid = (top + bottom) / 2;

        // if (matrix[mid][0] == target) return true;
        // else if (matrix[mid][0] < target) top = mid;
        // else bottom = mid - 1;

        // if (matrix[mid][n - 1] == target) return true;
        // else if (matrix[mid][n - 1] < target) top = mid + 1;
        // else bottom = mid;

        if (matrix[mid][0] == target || matrix[mid][n - 1] == target) return true;
        else if (target < matrix[mid][0]) bottom = mid - 1;
        else if (target > matrix[mid][n - 1]) top = mid + 1;
        else top = bottom = mid;
    }

    if (top > bottom) return false;
    if (target < matrix[top][0]) return false;
    if (target > matrix[bottom][n - 1]) return false;

    int row = top;
    int left = 0;
    int right = n - 1;
    while (left <= right){
        int mid = (left + right) / 2;

        if (matrix[row][mid] == target) return true;
        else if (target < matrix[row][mid]) right = mid - 1;
        else left = mid + 1;
    }

    return false;
}