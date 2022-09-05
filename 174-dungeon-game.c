// almost directly copied from
// https://leetcode.cn/problems/dungeon-game/solution/di-xia-cheng-you-xi-by-leetcode-solution/

#include<assert.h>

int min(int a, int b){
    return a <= b ? a : b;
}

int max(int a, int b){
    return a >= b ? a : b;
}

int calculateMinimumHP(int **dungeon, int dungeonSize, int *dungeonColSize){
    int m = dungeonSize;
    int n = dungeonColSize[0];
    for (int i = 1; i < m; i += 1){
        assert(dungeonColSize[i] == n);
    }

    int **dp = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i += 1){
        dp[i] = (int**)malloc(sizeof(int*) * n);
    }

    dp[m - 1][n - 1] = max(-dungeon[m - 1][n - 1], 0) + 1;
    for (int i = m - 2; i >= 0; i -= 1){
        dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 1);
    }
    for (int j = n - 2; j >= 0; j -= 1){
        dp[m - 1][j] = max(dp[m - 1][j + 1] - dungeon[m - 1][j], 1);
    }

    for (int i = m - 2; i >= 0; i -= 1){
        for (int j = n - 2; j >= 0; j -= 1){
            dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
        }
    }

    return dp[0][0];
}