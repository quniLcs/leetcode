#include<stdio.h>

// find the median is equal to find a partition so that
// half = (nums1Size + nums2Size) / 2
// nums1 become nums1[0:part-1] and nums1[part:nums1Size-1]
// nums1 become nums2[0:half-part-1] and nums2[half-part:nums2Size-1]
// nums1[part-1] <= nums2[half-part] and nums2[half-part-1] <= nums1[part]

int max(a, b){
    return a > b ? a : b;
}

int min(a, b){
    return a < b ? a : b;
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size){
    int part, current;
    int total = nums1Size + nums2Size;
    int half = total / 2;
    int left = max(0, half - nums2Size);
    int right = min(nums1Size, half) + 1;

    while (left + 1 < right){
        current = (left + right) / 2;
        if (nums1[current - 1] > nums2[half - current]){
            right = current;
        }
        else if(nums2[half - current - 1] > nums1[current]){
            left = current;
        }
        else{
            break;
        }
    }
    part = (left + right) / 2;

    if (total % 2){
        return min(nums1[part], nums2[half - part]);
    }
    else{
        return (max(nums1[part - 1], nums2[half - part - 1]) + min(nums1[part], nums2[half - part])) / 2.0;
    }
}


void main(){
    int nums1[2] = {1, 3}, nums2[1] = {2};
    printf("%.5f\n", findMedianSortedArrays(nums1, 2, nums2, 1));

    int nums3[2] = {1, 2}, nums4[2] = {3, 4};
    printf("%.5f\n", findMedianSortedArrays(nums3, 2, nums4, 2));
}