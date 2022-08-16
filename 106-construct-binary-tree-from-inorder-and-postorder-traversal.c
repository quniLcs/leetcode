#include<stdio.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *buildTree(int *inorder, int inorderSize, int* postorder, int postorderSize){
    assert(inorderSize == postorderSize);

    int inorderIndex = 0;
    while (inorder[inorderIndex] != postorder[postorderSize - 1]){
        inorderIndex += 1;
    }

    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> val = postorder[postorderSize - 1];
    root -> left = inorderIndex == 0 ? NULL : buildTree(inorder, inorderIndex, postorder, inorderIndex);
    root -> right = inorderIndex == inorderSize - 1 ? NULL : buildTree(inorder + 1 + inorderIndex, inorderSize - 1 - inorderIndex, postorder + inorderIndex, inorderSize - 1 - inorderIndex);
    return root;    
}