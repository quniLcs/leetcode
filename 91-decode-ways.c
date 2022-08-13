int numDecodings(char *s){
    int n = strlen(s);
    int *dp = (int*)malloc(sizeof(int) * (n + 1));
    
    dp[n] = 1;
    if (s[n - 1] == '0') dp[n - 1] = 0;
    else dp[n - 1] = 1;

    for (int i = n - 2; i >= 0; i -= 1){
        if (s[i] == '0') dp[i] = 0;
        else if (s[i] == '1') dp[i] = dp[i + 1] + dp[i + 2];
        else if (s[i] == '2' && s[i + 1] <= '6') dp[i] = dp[i + 1] + dp[i + 2];
        else dp[i] = dp[i + 1];
    }

    return dp[0];    
}