#include<stdio.h>
#define INT_MAX 2147483647

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode *root){
    if (root == NULL){
        return 0;
    }
    else if (root -> left == NULL && root -> right == NULL){
        return 1;
    }
    else{
        int leftDepth = root -> left == NULL ? INT_MAX : minDepth(root -> left);
        int rightDepth = root -> right == NULL ? INT_MAX : minDepth(root -> right);
        return leftDepth <= rightDepth ? leftDepth + 1 : rightDepth + 1;
    }
}