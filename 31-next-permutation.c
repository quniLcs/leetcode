// Almost directly copied from
// https://leetcode.cn/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode-solution/


void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void reverse(int *nums, int left, int right){
    while (left < right){
        swap(nums + left, nums + right);
        left++;
        right--;
    }
}


void nextPermutation(int *nums, int numsSize){
    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;

    if (i >= 0){
        int j = numsSize - 1;
        while (nums[i] >= nums[j]) j--;
        swap(nums + i, nums + j);
    }

    reverse(nums, i + 1, numsSize - 1);
}