#include<stdio.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize){
    assert(preorderSize == inorderSize);

    int inorderIndex = 0;
    while (inorder[inorderIndex] != preorder[0]){
        inorderIndex += 1;
    }

    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> val = preorder[0];
    root -> left = inorderIndex == 0 ? NULL : buildTree(preorder + 1, inorderIndex, inorder, inorderIndex);
    root -> right = inorderIndex == inorderSize - 1 ? NULL : buildTree(preorder + 1 + inorderIndex, inorderSize - 1 - inorderIndex, inorder + 1 + inorderIndex, inorderSize - 1 - inorderIndex);
    return root;    
}