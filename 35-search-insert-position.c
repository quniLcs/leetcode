int searchInsert(int *nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid;

    while (left < right){
        mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    if (nums[numsSize - 1] < target) return numsSize;
    else return left;
}