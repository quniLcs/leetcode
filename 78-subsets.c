int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes){
    // *returnSize = 2 ^ numsSize
    *returnSize = 1 << numsSize;

    int **result = (int**)malloc(sizeof(int*) * (*returnSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));

    for (int index = 0; index < *returnSize; index++){
        result[index] = (int*)malloc(sizeof(int) * numsSize);
        (*returnColumnSizes)[index] = 0;

        int bit = 0;
        int criterion = index;

        while (criterion){
            if (criterion & 1){
                result[index][(*returnColumnSizes)[index]] = nums[bit];
                (*returnColumnSizes)[index]++;
            }

            bit++;
            criterion >>= 1;
        }
    }

    return result;
}

void main(){
    int *nums = (int*)malloc(sizeof(int));
    nums[0] = 0;

    int returnSize;
    int *returnColumnSizes;
    subsets(nums, 1, &returnSize, &returnColumnSizes);
}