int removeDuplicates(int *nums, int numsSize){
    int returnSize = 0;

    for (int index = 0; index < numsSize; index++){
        if (returnSize >= 2 && nums[returnSize - 2] == nums[returnSize - 1] && nums[index] == nums[returnSize - 1]) continue;
        else nums[returnSize++] = nums[index];
    }

    return returnSize;
}