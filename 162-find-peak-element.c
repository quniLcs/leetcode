#include<stdbool.h>

int findPeakElement(int *nums, int numsSize){
    int start = 0;
    int end = numsSize - 1;

    while (start < end){
        int mid = (start + end) / 2;
        bool left = mid == 0 || nums[mid] > nums[mid - 1];
        bool right = mid == numsSize - 1 || nums[mid] > nums[mid + 1];
        if (left && right) return mid;
        else if (!left) end = mid - 1;
        else start = mid + 1;
    }
    return start;
}