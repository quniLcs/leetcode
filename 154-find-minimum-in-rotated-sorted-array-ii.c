int findMin(int *nums, int numsSize){
    int left = 0;
    int right = numsSize - 1;

    while (left < right){
        int mid = (left + right) / 2;
        if (nums[left] > nums[mid]){
            left += 1;
            right = mid;
        }
        else if (nums[right] < nums[mid]){
            left = mid + 1;
        }
        else if (nums[left] == nums[mid] && nums[right] == nums[mid]){
            left += 1;
            right -= 1;
        }
        else{
            break;
        }
    }
    
    return nums[left];
}