#include<stdio.h>
#include<stdbool.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool ans;

int maxDepth(struct TreeNode *root){
    if (root == NULL){
        return 0;
    }
    else{
        int leftDepth = maxDepth(root -> left);
        int rightDepth = maxDepth(root -> right);
        int difference = leftDepth - rightDepth;
        if (difference > 1 || difference < -1) ans = false;
        return leftDepth >= rightDepth ? leftDepth + 1 : rightDepth + 1;
    }
}

bool isBalanced(struct TreeNode *root){
    ans = true;
    maxDepth(root);
    return ans;
}