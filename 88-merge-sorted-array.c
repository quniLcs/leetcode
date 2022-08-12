#include<assert.h>
#include<stdbool.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n){
    assert(nums1Size == m + n);
    assert(nums2Size == n);

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    bool b;
    // true : choose nums1
    // false: choose nums2

    while (k >= 0){
        if (i < 0) b = false;
        else if (j < 0) b = true;
        else if (nums1[i] < nums2[j]) b = false;
        else b = true;

        if (b) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
}