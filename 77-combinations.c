int **ans;
int *ansColumnSizes;
int ansSize;

void combineRecursively(int n, int m, int k){
    // 1 <= k <= n

    if (k == 1){
        for (int i = 1; i <= n; i++){
            ans[ansSize] = (int*)malloc(sizeof(int) * m);
            ans[ansSize][0] = i;
            ansColumnSizes[ansSize] = 1;
            ansSize++;
        }
    }
    else{
        // not choosing n
        if (k < n) combineRecursively(n - 1, m, k);

        // choosing n
        int start = ansSize;
        combineRecursively(n - 1, m, k - 1);
        for (int i = start; i < ansSize; i++){
            ans[i][ansColumnSizes[i]] = n;
            ansColumnSizes[i]++;
        }
    }
}

int **combine(int n, int k, int *returnSize, int **returnColumnSizes){
    *returnSize = 1;  // n(n-1)...(n-k+1))/k(k-1)...1
    for (int i = 1; i <= k; i++){
        *returnSize = *returnSize * (n - k + i) / i;
    }

    ans = (int**)malloc(sizeof(int*) * (*returnSize));
    ansColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    ansSize = 0;

    combineRecursively(n, k, k);
    *returnColumnSizes = ansColumnSizes;
    return ans;    
}