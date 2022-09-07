void rotate(int *nums, int numsSize, int k){
    k %= numsSize;
    for (int i = 0, j = -1, p = -1, q = -1, num = 0; i < numsSize; i += 1, p = q){
        // j: the first index of this round of moving
        // p: the index of number we are going to move
        // q: the target index we are going to move to
        // num: the stored number
        if (p == j){
            p += 1;
            j += 1;
            q = (p + k) % numsSize;
            num = nums[q];
            nums[q] = nums[p];
        }
        else{
            q = (p + k) % numsSize;
            int temp = num;
            num = nums[q];
            nums[q] = temp;
        }
    }
}