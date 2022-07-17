// finally refer to:
// https://leetcode.cn/problems/3sum-closest/solution/zui-jie-jin-de-san-shu-zhi-he-by-leetcode-solution/

#include<stdio.h>

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target){
    qsort((void*)nums, (size_t)numsSize, sizeof(int), compare);

    int ans = 1e5;
    for (int first = 0; first < numsSize; first++){
        if (first == 0 || nums[first] != nums[first - 1]){
            int second = first + 1, third = numsSize - 1;
            while (second < third){
                int sum = nums[first] + nums[second] + nums[third];

                if (sum == target) return target;
                else if (abs(sum - target) < abs(ans - target)) ans = sum;

                if (sum > target){
                    do third--;
                    while (second < third && nums[third] == nums[third + 1]);
                }
                else{
                    do second++;
                    while (second < third && nums[second] == nums[second - 1]);
                }
            }
        }
    }
    return ans;
}

void main(){
    int nums[4] = {-1, 2, 1, -4};
    // after sort {-4, -1, 1, 2}

    printf("%d\n", threeSumClosest(nums, 4, 1));
}