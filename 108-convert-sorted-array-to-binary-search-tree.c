#include<stdio.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *sortedArrayToBST(int *nums, int numsSize){
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> val = nums[numsSize / 2];
    root -> left = numsSize == 1 ? NULL : sortedArrayToBST(nums, numsSize / 2);
    root -> right = numsSize <= 2 ? NULL : sortedArrayToBST(nums + numsSize / 2 + 1, (numsSize - 1) / 2);
    return root;
}