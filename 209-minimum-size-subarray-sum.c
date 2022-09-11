int minSubArrayLen(int target, int *nums, int numsSize){
    int sum = 0;
    int left = 0;
    int right = 0;

    while (sum < target && right < numsSize){
        sum += nums[right];
        right += 1;
    }
    if (sum < target){
        return 0;
    }

    int min = right;
    while (left < numsSize){
        sum -= nums[left];
        left += 1;
        while (sum < target && right < numsSize){
            sum += nums[right];
            right += 1;
        }
        if (sum < target){
            break;
        }
        else{
            if (right - left < min){
                min = right - left;
            }
        }
    }
    return min;
}