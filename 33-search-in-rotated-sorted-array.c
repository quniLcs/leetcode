#include<stdio.h>


/* original code
int index(int i, int numsSize){
    if (i < 0) return i + numsSize;
    else return i;
}

int search(int *nums, int numsSize, int target){
    // first find k
    int left = 0;
    int right = numsSize;
    int mid, k;
    while (left < right){
        mid = (left + right) / 2;
        if (mid == 0){
            break;
        }
        else if (nums[mid] < nums[0]){
            if (nums[mid] < nums[mid - 1]) break;
            else right = mid;
        }
        else{  // nums[mid] > nums[0]
            left = mid + 1;
        }
    }
    if (left < right) k = mid;
    else k = 0;

    // then find ans
    left = k - numsSize;
    right = k - 1;
    int i, ans = -1;
    while (left <= right){
        mid = (left + right) / 2;
        i = index(mid, numsSize);
        if (nums[i] == target){
            ans = i;
            break;
        }
        else if (nums[i] < target){
            left = mid + 1;
        }
        else{  // nums[i] > target
            right = mid - 1;
        }
    }
    return ans;
}
*/


// code with reference to:
// https://leetcode.cn/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-leetcode-solut/
int search(int *nums, int numsSize, int target){
    int left = 0;
    int right = numsSize;
    int mid;

    while (left < right){
        mid = (left + right) / 2;
        if (nums[mid] == target){
            return mid;
        }
        else if (nums[0] <= nums[mid]){
            if (nums[left] <= target && target < nums[mid]) right = mid;
            else left = mid + 1;
        }
        else{
            if (nums[mid] < target && target <= nums[right - 1]) left = mid + 1;
            else right = mid;
        }
    }
    return -1;
}


void main(){
    // int nums[7] = {4, 5, 6, 7, 0, 1, 2};
    // printf("%d\n", search(nums, 7, 0));
    int nums[2] = {1, 3};
    printf("%d\n", search(nums, 2, 3));
}