int maxProduct(int *nums, int numsSize){
    int pos = 0;
    int neg = 0;
    int ans = -10;

    for (int index = 0; index < numsSize; index += 1){
        if (nums[index] >= 0){
            if (pos) pos = pos * nums[index];
            else pos = nums[index];
            neg = neg * nums[index];
        }
        else{
            int temp = neg * nums[index];
            if (pos) neg = pos * nums[index];
            else neg = nums[index];
            pos = temp;
        }
        if (pos > ans) ans = pos;
        else if (neg > ans) ans = neg;
    }

    return ans;
}