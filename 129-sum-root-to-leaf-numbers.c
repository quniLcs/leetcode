#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int ans;

void sumRecursively(struct TreeNode *root, int cur){
    cur = cur * 10 + root -> val;

    if (root -> left == NULL && root -> right == NULL){
        ans += cur;
    }
    else{
        if (root -> left) sumRecursively(root -> left, cur);
        if (root -> right) sumRecursively(root -> right, cur);
    }
}

int sumNumbers(struct TreeNode *root){
    ans = 0;
    sumRecursively(root, 0);
    return ans;
}