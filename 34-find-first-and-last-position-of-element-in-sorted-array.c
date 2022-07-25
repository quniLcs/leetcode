int *searchRange(int *nums, int numsSize, int target, int *returnSize){
    int *ret = (int*)malloc(sizeof(int) * 2);
    ret[0] = ret[1] = -1;
    *returnSize = 2;

    int left = 0;
    int right = numsSize - 1;
    int mid, temp = -1;
    while (left <= right){
        mid = (left + right) / 2;
        if (nums[mid] == target){
            if (mid == 0 || nums[mid - 1] != target){
                ret[0] = mid;
                break;
            }
            else{
                right = mid - 1;
            }
        }
        else if (nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
            temp = mid;
        }
    }

    left = ret[0] != -1 ? 0 : numsSize;
    right = temp != -1 ? temp : numsSize - 1;
    while (left <= right){
        mid = (left + right) / 2;
        if (nums[mid] == target){
            if (mid == numsSize - 1 || nums[mid + 1] != target){
                ret[1] = mid;
                break;
            }
            else{
                left = mid + 1;
            }
        }
        else if (nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return ret;
}