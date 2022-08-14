int numTrees(int n){
    int *dp = (int*)malloc(sizeof(int) * (n + 1));

    dp[0] = 1;
    for (int index = 1; index <= n; index += 1){
        dp[index] = 0;
        for (int middle = 1; middle <= index; middle += 1){
            dp[index] += dp[middle - 1] * dp[index - middle];
        }
    }
    
    return dp[n];
}