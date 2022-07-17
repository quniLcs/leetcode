// just convert the c++ to c with reference to
// https://leetcode.cn/problems/3sum/solution/san-shu-zhi-he-by-leetcode-solution/

#include<stdio.h>

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes){
    qsort((void*)nums, (size_t)numsSize, sizeof(int), compare);

    int **ans = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
    *returnSize = 0;

    for (int first = 0; first < numsSize; first++){
        if (first == 0 || nums[first] != nums[first - 1]){
            int third = numsSize - 1;
            for (int second = first + 1; second < numsSize; second++){
                if (second == first + 1 || nums[second] != nums[second - 1]){
                    while (second < third && nums[first] + nums[second] + nums[third] > 0){
                        third--;
                    }
                    if (second == third){
                        break;
                    }
                    if (nums[first] + nums[second] + nums[third] == 0){
                        ans[*returnSize] = (int*)malloc(sizeof(int) * 3);
                        ans[*returnSize][0] = nums[first];
                        ans[*returnSize][1] = nums[second];
                        ans[*returnSize][2] = nums[third];
                        (*returnColumnSizes)[*returnSize] = 3;
                        (*returnSize)++;
                    }
                }
            }
        }
    }
    
    return ans;
}


void main(){
    int nums[6] = {-1, 0, 1, 2, -1, -4};
    // after sort {-4, -1, -1, 0, 1, 2}

    int numsSize = 6;
    int returnSize = 0;
    int **returnColumnSizes = (int**)malloc(sizeof(int*) * numsSize * numsSize);

    int **ans = threeSum(nums, numsSize, &returnSize, returnColumnSizes);
    for (int index = 0; index < returnSize; index++){
        printf("%d\t%d\t%d\n", ans[index][0], ans[index][1], ans[index][2]);
    }
}
