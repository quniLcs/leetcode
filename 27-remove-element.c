int removeElement(int *nums, int numsSize, int val){
    int returnSize = 0;
    
    for (int index = 0; index < numsSize; index++){
        if (nums[index] != val){
            nums[returnSize] = nums[index];
            returnSize++;
        }
    }

    return returnSize;
}