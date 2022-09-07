int max(int a, int b){
    return a >= b ? a : b;
}

int rob(int *nums, int numsSize){
    int *a = (int*)malloc(sizeof(int) * numsSize);
    int *b = (int*)malloc(sizeof(int) * numsSize);
    // a: rob the current house
    // b: don't rob the current house

    a[0] = nums[0];
    b[0] = 0;
    for (int i = 1; i < numsSize; i += 1){
        a[i] = b[i - 1] + nums[i];
        b[i] = max(a[i - 1], b[i - 1]);
    }

    return max(a[numsSize - 1], b[numsSize - 1]);
}