// original O(nk) code
// time limit exceeded
/* 
#include<stdio.h>

struct item{
    int value;
    struct item *next;
};

void insert(struct item *dummy, int num){
    struct item *current = dummy;
    while (current -> next && current -> next -> value < num){
        current = current -> next;
    }
    struct item *new = (struct item*)malloc(sizeof(struct item));
    new -> value = num;
    new -> next = current -> next;
    current -> next = new;
}

struct item *delete(struct item *dummy){
    struct item *head = dummy -> next;
    free(dummy);
    return head;
}

int findKthLargest(int *nums, int numsSize, int k){
    struct item *dummy = (struct item*)malloc(sizeof(struct item));
    dummy -> value = 0;
    dummy -> next = NULL;

    for (int i = 0; i < k; i += 1){
        insert(dummy, nums[i]);
    }

    for (int i = k; i < numsSize; i += 1){
        if (dummy -> next -> value < nums[i]){
            insert(dummy, nums[i]);
            dummy = delete(dummy);
        }
    }

    int ans = dummy -> next -> value;
    for (int i = 0; i <= k; i += 1){
        dummy = delete(dummy);
    }
    return ans;
}
*/


// quick select
// with reference to
// https://leetcode.cn/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/
int partition(int *nums, int left, int right) {
    int pivot = rand() % (right - left + 1) + left;
    int temp = nums[pivot];
    nums[pivot] = nums[right];
    nums[right] = temp;

    pivot = left;
    for (int index = left; index < right; index += 1){
        if (nums[index] < nums[right]){
            temp = nums[pivot];
            nums[pivot] = nums[index];
            nums[index] = temp;
            pivot += 1;
        }
    }
    
    temp = nums[pivot];
    nums[pivot] = nums[right];
    nums[right] = temp;
    return pivot;
}

int quickSelect(int *nums, int left, int right, int index){
    int pivot = partition(nums, left, right);
    if (pivot == index) return nums[pivot];
    else if (pivot < index) return quickSelect(nums, pivot + 1, right, index);
    else return quickSelect(nums, left, pivot - 1, index);
}

int findKthLargest(int *nums, int numsSize, int k){
    return quickSelect(nums, 0, numsSize - 1, numsSize - k);
}