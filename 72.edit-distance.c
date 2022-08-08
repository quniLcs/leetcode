#include<stdio.h>

int min(int a, int b){
    return a < b ? a : b;
}

int minDistance(char *word1, char *word2){
    int m = strlen(word1);
    int n = strlen(word2);

    int **dp = (int**)malloc(sizeof(int*) * (m + 1));
    for (int i = 0; i <= m; i++){
        dp[i] = (int*)malloc(sizeof(int) * (n + 1));
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; j++){
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
            // printf("%d\t", dp[i][j]);
        }
        // printf("\n");
    }

    return dp[m][n];
}

void main(){
    minDistance("horse", "ros");
}