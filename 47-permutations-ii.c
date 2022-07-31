// the following is referred to
// https://leetcode.cn/problems/permutations-ii/solution/quan-pai-lie-ii-by-leetcode-solution/

#include<stdio.h>
#include<stdbool.h>

int **ans;
int *ansColumnSizes;
int ansSize;

int *perm;
bool *visited;

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

void permuteRecursively(int *nums, int numSize, int curSize){
    if (curSize == numSize){
        ans[ansSize] = (int*)malloc(sizeof(int) * numSize);
        memcpy(ans[ansSize], perm, sizeof(int) * numSize);
        ansColumnSizes[ansSize] = numSize;
        ansSize++;
    }
    else{
        for (int i = 0; i < numSize; i++){
            if (visited[i] || i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]){
                continue;
            }
            else{
                perm[curSize] = nums[i];
                visited[i] = true;
                permuteRecursively(nums, numSize, curSize + 1);
                visited[i] = false;
            }
        }
    }
}

int **permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes){
    qsort((void*)nums, (size_t)numsSize, sizeof(int), compare);

    ans = (int**)malloc(sizeof(int*) * 40320);
    ansColumnSizes = (int*)malloc(sizeof(int) * 40320);
    ansSize = 0;

    perm = (int*)malloc(sizeof(int) * numsSize);
    visited = (bool*)malloc(sizeof(bool) * numsSize);
    memset(visited, false, sizeof(bool) * numsSize);

    permuteRecursively(nums, numsSize, 0);
    *returnSize = ansSize;
    *returnColumnSizes = ansColumnSizes;
    return ans;
}