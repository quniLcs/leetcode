#include<stdio.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void invertTreeRecursively(struct TreeNode *root){
    struct TreeNode *temp = root -> left;
    root -> left = root-> right;
    root -> right = temp;

    if (root -> left) invertTreeRecursively(root -> left);
    if (root -> right) invertTreeRecursively(root -> right);
}

struct TreeNode *invertTree(struct TreeNode *root){
    if (root == NULL) return NULL;
    else invertTreeRecursively(root); return root;
}