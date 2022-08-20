#include<assert.h>

int min(int a, int b){
    return a < b ? a : b;
}

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize){
    for (int i = 0; i < triangleSize; i += 1){
        assert(triangleColSize[i] == i + 1);
    }

    int *dp = (int*)malloc(sizeof(int) * triangleSize);
    dp[0] = triangle[0][0];
    for (int i = 1; i < triangleSize; i += 1){
        dp[i] = dp[i - 1] + triangle[i][i];
        for (int j = i - 1; j > 0; j -= 1){
            dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
        }
        dp[0] += triangle[i][0];
    }

    int ans = dp[0];
    for (int j = 1; j < triangleSize; j += 1){
        ans = min(ans, dp[j]);
    }
    return ans;
}