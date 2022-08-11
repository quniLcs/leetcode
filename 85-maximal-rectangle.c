// almost directly copied from
// https://leetcode.cn/problems/maximal-rectangle/solution/zui-da-ju-xing-by-leetcode-solution-bjlu/


#include<assert.h>

int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}

int maximalRectangle(char **matrix, int matrixSize, int *matrixColSize){
    int m = matrixSize;
    int n = matrixColSize[0];
    for (int i = 1; i < m; i++){
        assert(matrixColSize[i] == n);
    }

    int **ones = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++){
        ones[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == '0') ones[i][j] = 0; 
            else ones[i][j] = j == 0 ? 1 : (ones[i][j - 1] + 1); 
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == '1'){
                int width = ones[i][j];
                int area = width;
                for (int k = i - 1; k >= 0; k--){
                    width = min(width, ones[k][j]);
                    area = max(area, (i - k + 1) * width);
                }
                ans = max(ans, area);
            }
        }
    }
    return ans;
}