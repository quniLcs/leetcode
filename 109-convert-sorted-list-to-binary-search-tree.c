#include<stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *buildBST(int size){
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> val = 0;
    root -> left = size == 1 ? NULL : buildBST(size / 2);
    root -> right = size <= 2 ? NULL : buildBST((size - 1) / 2);
    return root;
}

struct TreeNode *sortedListToBST(struct ListNode *head){
    // get the length of the list
    int size = 0;
    struct ListNode *current = head;
    while (current){
        size += 1;
        current = current -> next;
    }

    // build the structure of the tree
    struct TreeNode *root = buildBST(size);
}