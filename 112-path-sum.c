#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int targetSum){
    if (root == NULL){
        return false;
    }
    else if (root -> left == NULL && root -> right == NULL){
        return root -> val == targetSum;
    }
    else{
        if (root -> left != NULL && hasPathSum(root -> left, targetSum - root -> val)) return true;
        if (root -> right != NULL && hasPathSum(root -> right, targetSum - root -> val)) return true;
        return false;
    }
}