// almost directly copied from
// https://leetcode.cn/problems/product-of-array-except-self/solution/chu-zi-shen-yi-wai-shu-zu-de-cheng-ji-by-leetcode-/

int *productExceptSelf(int *nums, int numsSize, int *returnSize){
    int *left = (int*)malloc(sizeof(int) * numsSize);
    int *right = (int*)malloc(sizeof(int) * numsSize);
    int *ans = (int*)malloc(sizeof(int) * numsSize);

    left[0] = 1;
    right[numsSize - 1] = 1;

    for (int index = 1; index < numsSize; index += 1) left[index] = nums[index - 1] * left[index - 1];    
    for (int index = numsSize - 2; index >= 0; index -= 1)  right[index] = nums[index + 1] * right[index + 1];
    for (int index = 0; index < numsSize; index += 1) ans[index] = left[index] * right[index];

    *returnSize = numsSize;
    return ans;
}