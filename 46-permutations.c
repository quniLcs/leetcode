int **ans;
int *ansColumnSizes;
int ansSize;

void permuteRecursively(int *nums, int numsSize){
    if (numsSize == 1){
        ans[ansSize] = (int*)malloc(sizeof(int) * 6);
        ans[ansSize][0] = nums[0];
        ansColumnSizes[ansSize] = 1;
        ansSize += 1;
    }
    else{
        for (int i = 0; i < numsSize; i++){
            int last = nums[i];
            nums[i] = nums[numsSize - 1];

            int beforeSize = ansSize;
            permuteRecursively(nums, numsSize - 1);
            for (int j = beforeSize; j < ansSize; j++){
                ans[j][numsSize - 1] = last;
                ansColumnSizes[j] += 1;
            }

            nums[i] = last;
        }
    }
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes){
    ans = (int**)malloc(sizeof(int*) * 720);
    ansColumnSizes = (int*)malloc(sizeof(int) * 720);
    ansSize = 0;

    permuteRecursively(nums, numsSize);
    *returnSize = ansSize;
    *returnColumnSizes = ansColumnSizes;
    return ans;
}