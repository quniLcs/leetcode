// almost directly copied from
// https://leetcode.cn/problems/single-number/solution/zhi-chu-xian-yi-ci-de-shu-zi-by-leetcode-solution/

int singleNumber(int *nums, int numsSize){
    int ans = 0;
    for (int index = 0; index < numsSize; index += 1){
        ans ^= nums[index];
    }
    return ans;
}