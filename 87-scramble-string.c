// almost directly copied from
// https://leetcode.cn/problems/scramble-string/solution/rao-luan-zi-fu-chuan-by-leetcode-solutio-8r9t/


#include<stdbool.h>

int dp[30][30][31];
//  0: uncalculated
// -1: false
//  1: true

bool dfs(char *s1, char *s2, int i1, int i2, int len){
    if (dp[i1][i2][len]){
        return dp[i1][i2][len] == 1;
    }

    if (len == 1){
        if (s1[i1] == s2[i2]){
            dp[i1][i2][len] = 1;
            return true;
        }
        else{
            dp[i1][i2][len] = -1;
            return false;
        }
    }
    else{
        for (int i = 1; i < len; i++){
            if (dfs(s1, s2, i1, i2, i) && dfs(s1, s2, i1 + i, i2 + i, len - i)){
                dp[i1][i2][len] = 1;
                return true;
            }
            if (dfs(s1, s2, i1, i2 + len - i, i) && dfs(s1, s2, i1 + i, i2, len - i)){
                dp[i1][i2][len] = 1;
                return true;
            }
        }
        dp[i1][i2][len] = -1;
        return false;
    }
}

bool isScramble(char *s1, char *s2){
    memset(dp, 0, sizeof(dp));
    return dfs(s1, s2, 0, 0, strlen(s1));
}