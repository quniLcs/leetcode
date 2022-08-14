#include<stdbool.h>

bool isInterleave(char *s1, char *s2, char *s3){
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int n3 = strlen(s3);
    if (n1 + n2 != n3) return false;

    bool **dp = (bool**)malloc(sizeof(bool*) * (n1 + 1));
    for (int i1 = 0; i1 <= n1; i1 += 1){
        dp[i1] = (bool*)malloc(sizeof(bool) * (n2 + 1));
        memset(dp[i1], false, sizeof(bool) * (n2 + 1));
    }
    
    dp[0][0] = true;
    for (int i1 = 1; i1 <= n1 && s1[i1 - 1] == s3[i1 - 1]; i1 += 1) dp[i1][0] = true;
    for (int i2 = 1; i2 <= n2 && s2[i2 - 1] == s3[i2 - 1]; i2 += 1) dp[0][i2] = true;
    
    for (int i1 = 1; i1 <= n1; i1 += 1){
        for (int i2 = 1; i2 <= n2; i2 += 1){
            if (dp[i1 - 1][i2] && s1[i1 - 1] == s3[i1 + i2 - 1] || dp[i1][i2 - 1] && s2[i2 - 1] == s3[i1 + i2 - 1]) dp[i1][i2] = true;
        }
    }

    return dp[n1][n2];
}