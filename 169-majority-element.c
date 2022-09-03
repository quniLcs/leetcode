// almost directly copied from
// https://leetcode.cn/problems/majority-element/solution/duo-shu-yuan-su-by-leetcode-solution/

#include<stdbool.h>

int majorityElement(int *nums, int numsSize){
    while (true){
        int candidate = nums[rand() % numsSize];
        int count = 0;
        for (int index = 0; index < numsSize; index += 1){
            if (nums[index] == candidate) count += 1;
        }
        if (count > numsSize / 2)
            return candidate;
    }
    return 0;
}