// almost directly copied from
// https://leetcode.cn/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/

#include<stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize){
    int pre = nums[0];
    int ans = nums[0];
    for (int index = 1; index < numsSize; index++){
        pre = max(pre + nums[index], nums[index]);
        ans = max(ans, pre);
    }
    return ans;
}

void main(){
    int nums[] = {0, 0, -3, 1};
    printf("%d\n", maxSubArray(nums, 4));
}