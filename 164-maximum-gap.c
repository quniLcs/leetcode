// radix sort almost directly copied from
// https://leetcode.cn/problems/maximum-gap/solution/zui-da-jian-ju-by-leetcode-solution/

int maximumGap(int *nums, int numsSize){
    int max = 0;
    for (int index = 0; index < numsSize; index += 1) {
        if (nums[index] > max){
            max = nums[index];
        }
    }

    int exp = 1;
    int *buffer = (int*)malloc(sizeof(int) * numsSize);
    int *count = (int*)malloc(sizeof(int) * 10);
    memset(buffer, 0, sizeof(int) * numsSize);
    while (max >= exp){
        memset(count, 0, sizeof(int) * 10);
        for (int index = 0; index < numsSize; index += 1){
            int digit = nums[index] / exp % 10;
            count[digit] += 1;
        }
        for (int index = 1; index < 10; index += 1){
            count[index] += count[index - 1];
        }
        for (int index = numsSize - 1; index >= 0; index -= 1){
            int digit = nums[index] / exp % 10;
            count[digit] -= 1;
            buffer[count[digit]] = nums[index];
        }
        memcpy(nums, buffer, sizeof(int) * numsSize);
        exp *= 10;
    }

    int ans = 0;
    for (int index = 1; index < numsSize; index += 1){
        if (nums[index] - nums[index - 1] > ans){
            ans = nums[index] - nums[index - 1];
        }
    }
    return ans;
}