#include<stdbool.h>
#include<assert.h>

int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize){
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    for (int i = 1; i < m; i++){
        assert(obstacleGridColSize[i] == n);
    }

    int dp[100][100];
    bool obstacled = false;
    for (int j = 0; j < n; j++){
        if (obstacled){
            dp[0][j] = 0;
        }
        else if (obstacleGrid[0][j]){
            dp[0][j] = 0;
            obstacled = true;
        }
        else{
            dp[0][j] = 1;
        }
    }

    obstacled = false;
    for (int i = 0; i < m; i++){
        if (obstacled){
            dp[i][0] = 0;
        }
        else if (obstacleGrid[i][0]){
            dp[i][0] = 0;
            obstacled = true;
        }
        else{
            dp[i][0] = 1;
        }
    }

    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            if (obstacleGrid[i][j]) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}