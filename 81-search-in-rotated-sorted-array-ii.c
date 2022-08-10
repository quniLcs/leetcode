#include<stdio.h>
#include<stdbool.h>

bool search(int *nums, int numsSize, int target){
    int left = 0;
    int right = numsSize;
    int mid;

    while (left < right){
        mid = (left + right) / 2;
        if (nums[mid] == target){
            return true;
        }
        else if (nums[left] == nums[mid]){
            return mid - left > 1 && search(nums + left + 1, mid - left - 1, target) || right - mid > 1 && search(nums + mid + 1, right - mid - 1, target);
        }
        else if (nums[left] < nums[mid]){
            if (nums[left] <= target && target < nums[mid]) right = mid;
            else left = mid + 1;
        }
        else{
            if (nums[mid] < target && target <= nums[right - 1]) left = mid + 1;
            else right = mid;
        }
    }
    return false;
}

void main(){
    int target = 2;
    int numsSize = 19;

    int *nums = (int*)malloc(sizeof(int) * numsSize);
    memset(nums, 1, sizeof(int) * numsSize);
    nums[13] = 2;

    printf("%d\n", search(nums, numsSize, target));    
}