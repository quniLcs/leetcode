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

struct ListNode *current;

struct TreeNode *buildBST(int size){
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> val = 0;
    root -> left = size == 1 ? NULL : buildBST(size / 2);
    root -> right = size <= 2 ? NULL : buildBST((size - 1) / 2);
    return root;
}

void inorderTraversal(struct TreeNode *root){
    if (root -> left) inorderTraversal(root -> left);
    root -> val = current -> val;
    current = current -> next;
    if (root -> right) inorderTraversal(root -> right);
}

struct TreeNode *sortedListToBST(struct ListNode *head){
    // get the length of the list
    int size = 0;
    current = head;
    while (current){
        size += 1;
        current = current -> next;
    }

    // build the structure of the tree
    struct TreeNode *root = size == 0 ? NULL : buildBST(size);

    // fill the value of the tree
    current = head;
    if (size) inorderTraversal(root);
    return root;
}