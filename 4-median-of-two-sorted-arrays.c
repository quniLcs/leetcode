// The first hard problem with reference to:
// https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/

#include<stdio.h>
#define INT_MIN -2147483648
#define INT_MAX  2147483647

// Two solutions are provided here and one is commented
// Acturally they are almost of same difficulty
/*
int min(a, b){
    return a < b ? a : b;
}

int getKthElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int k){
    int index1 = 0, index2 = 0;

    while (1){
        if (index1 == nums1Size) {
            return nums2[index2 + k - 1];
        }
        if (index2 == nums2Size) {
            return nums1[index1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[index1], nums2[index2]);
        }

        int newIndex1 = min(index1 + k / 2 - 1, nums1Size - 1);
        int newIndex2 = min(index2 + k / 2 - 1, nums2Size - 1);
        if (nums1[newIndex1] <= nums2[newIndex2]){
            k -= newIndex1 - index1 + 1;
            index1 = newIndex1 + 1;
        }
        else{
            k -= newIndex2 - index2 + 1;
            index2 = newIndex2 + 1;
        }
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size){
    int totalSize = nums1Size + nums2Size;

    if (totalSize % 2 == 1){
        return getKthElement(nums1, nums1Size, nums2, nums2Size, (totalSize + 1) / 2);
    }
    else{
        return (getKthElement(nums1, nums1Size, nums2, nums2Size, totalSize / 2) + getKthElement(nums1, nums1Size, nums2, nums2Size, totalSize / 2 + 1)) / 2.0;
    }
}
*/

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size){
    if (nums1Size > nums2Size){
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int left = 0;
    int right = nums1Size;

    int median1;  // max of the first part
    int median2;  // min of the second part

    while (left <= right) {
        // make a partition
        // the first  part is nums1[0:i-1] and nums2[0:j-1]
        // the second part is nums1[i:m-1] and nums2[j:n-1]
        int i = (left + right) / 2;
        int j = (nums1Size + nums2Size + 1) / 2 - i;

        int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
        int nums_i = (i == nums1Size ? INT_MAX : nums1[i]);
        int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
        int nums_j = (j == nums2Size ? INT_MAX : nums2[j]);

        if (nums_im1 <= nums_j){
            median1 = nums_im1 > nums_jm1 ? nums_im1 : nums_jm1;
            median2 = nums_i < nums_j ? nums_i : nums_j;
            left = i + 1;
        }
        else{
            right = i - 1;
        }
    }

    return (nums1Size + nums2Size) % 2 ? median1 : (median1 + median2) / 2.0;
}


void main(){
    int nums1[2] = {1, 3}, nums2[1] = {2};
    printf("%.5f\n", findMedianSortedArrays(nums1, 2, nums2, 1));

    int nums3[2] = {1, 2}, nums4[2] = {3, 4};
    printf("%.5f\n", findMedianSortedArrays(nums3, 2, nums4, 2));
}