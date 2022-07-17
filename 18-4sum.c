#include<stdio.h>

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int **fourSum(int* nums, int numsSize, int target, int *returnSize, int **returnColumnSizes){
    qsort((void*)nums, (size_t)numsSize, sizeof(int), compare);

    int **ans = (int**)malloc(sizeof(int*) * numsSize * numsSize * numsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize * numsSize);
    *returnSize = 0;

    for (int first = 0; first < numsSize; first++){
        if (first == 0 || nums[first] != nums[first - 1]){
            for (int second = first + 1; second < numsSize; second++){
                if (second == first + 1 || nums[second] != nums[second - 1]){
                    int fourth = numsSize - 1;
                    for (int third = second + 1; third < numsSize; third++){
                        if (third == second + 1 || nums[third] != nums[third - 1]){
                            while (third < fourth && (long)nums[first] + nums[second] + nums[third] + nums[fourth] > target){
                                fourth--;
                            }
                            if (third == fourth){
                                break;
                            }
                            if ((long)nums[first] + nums[second] + nums[third] + nums[fourth] == target){
                                ans[*returnSize] = (int*)malloc(sizeof(int) * 4);
                                ans[*returnSize][0] = nums[first];
                                ans[*returnSize][1] = nums[second];
                                ans[*returnSize][2] = nums[third];
                                ans[*returnSize][3] = nums[fourth];
                                (*returnColumnSizes)[*returnSize] = 4;
                                (*returnSize)++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return ans;
}


void main(){
    int nums[6] = {1, 0, -1, 0, -2, 2};
    // after sort {-2, -1, 0, 0, 1, 2}

    int numsSize = 6;
    int target = 0;
    int returnSize = 0;
    int **returnColumnSizes = (int**)malloc(sizeof(int*) * numsSize * numsSize * numsSize);

    int **ans = fourSum(nums, numsSize, target, &returnSize, returnColumnSizes);
    for (int index = 0; index < returnSize; index++){
        printf("%d\t%d\t%d\t%d\n", ans[index][0], ans[index][1], ans[index][2], ans[index][3]);
    }
}