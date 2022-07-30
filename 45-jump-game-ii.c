/* recursive solution but time limit exceeded
int jump(int *nums, int numsSize){
    // numsSize >= 1
    if (numsSize == 1){
        return 0;
    }
    else if (nums[0] >= numsSize - 1){
        return 1;
    }
    else{
        int ans = 2147483647 - 1;
        for (int i = 1; i <= nums[0]; i++){
            int cur = jump(nums + i, numsSize - i) + 1;
            ans = ans < cur ? ans : cur;
        }
        return ans;
    }
}
*/


/* dynamic programming
int jump(int *nums, int numsSize){
    int *dp = (int*)malloc(sizeof(int) * numsSize);
    dp[numsSize - 1] = 0;

    for (int i = numsSize - 2; i >= 0; i--){
        if (i + nums[i] >= numsSize - 1){
            dp[i] = 1;
        }
        else{
            dp[i] = 2147483647 - 1;
            for (int j = 1; j <= nums[i]; j++){
                int cur = dp[i + j] + 1;
                dp[i] = dp[i] < cur ? dp[i] : cur;
            }
        }
    }

    return dp[0];
}
*/


// greedy algorithms with reference to
// https://leetcode.cn/problems/jump-game-ii/solution/tiao-yue-you-xi-ii-by-leetcode-solution/
/*
int jump(int *nums, int numsSize){
    int step = 0;
    int cur = numsSize - 1;
        
    while (cur > 0){
        int next = 0;
        while (next + nums[next] < cur) next++;
        step++;
        cur = next;
    }
        
    return step;
}
*/


int jump(int *nums, int numsSize){
    int step = 0;
    int end = 0;
    int next = 0;

    for (int i = 0; i < numsSize - 1; i++){
        next = next > i + nums[i] ? next : i + nums[i];
        if (i == end){
            end = next;
            step++;
        }
    }

    return step;
}