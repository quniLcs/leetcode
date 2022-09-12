int **ans;
int *ansColumnSizes;
int ansSize;

int *cur;
int curSize;

void combinationRecursively(int k, int m){
    if (curSize == k){
        if (m == 0){
            ans[ansSize] = (int*)malloc(sizeof(int) * k);
            memcpy(ans[ansSize], cur, sizeof(int) * k);
            ansColumnSizes[ansSize] = k;
            ansSize += 1;
        }
    }
    else{
        int start = curSize ? cur[curSize - 1] + 1 : 1;
        int end = 10 - k + curSize;
        curSize += 1;
        for (int i = start; i <= end; i += 1){
            cur[curSize - 1] = i;
            combinationRecursively(k, m - i);
        }
        curSize -= 1;
    }
}

int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes){
    ans = (int**)malloc(sizeof(int*) * 128);
    ansColumnSizes = (int*)malloc(sizeof(int) * 128);
    ansSize = 0;

    cur = (int*)malloc(sizeof(int) * k);
    curSize = 0;

    combinationRecursively(k, n);

    *returnSize = ansSize;
    *returnColumnSizes = ansColumnSizes;
    return ans;
}