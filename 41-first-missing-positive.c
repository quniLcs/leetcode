// Almost directly copied from
// https://leetcode.cn/problems/first-missing-positive/solution/que-shi-de-di-yi-ge-zheng-shu-by-leetcode-solution/


/*
#include<math.h>

int firstMissingPositive(int *nums, int numsSize){
    for (int i = 0; i < numsSize; i++){
        if (nums[i] <= 0){
            nums[i] = numsSize + 1;
        }
    }

    for (int i = 0; i < numsSize; i++){
        int num = abs(nums[i]);
        if (num <= numsSize){
            nums[num - 1] = -abs(nums[num - 1]);
        }
    }

    for (int i = 0; i < numsSize; ++i){
        if (nums[i] > 0){
            return i + 1;
        }
    }
    return numsSize + 1;
}
*/


int firstMissingPositive(int *nums, int numsSize){
    for (int i = 0; i < numsSize; i++){
        while (0 < nums[i] && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]){
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }

    for (int i = 0; i < numsSize; i++){
        if (nums[i] != i + 1){
            return i + 1;
        }
    }
    return numsSize + 1;
}