#include<assert.h>

int min(int a, int b){
    return a < b ? a : b;
}

int minPathSum(int **grid, int gridSize, int *gridColSize){
    int m = gridSize;
    int n = gridColSize[0];
    for (int i = 1; i < m; i++){
        assert(gridColSize[i] == n);
    }

    int dp[200][200];
    dp[0][0] = grid[0][0];
    for (int j = 1; j < n; j++){
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++){
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[m - 1][n - 1];
}