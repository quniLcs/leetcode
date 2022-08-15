#include<stdio.h>
#include<stdbool.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool AreSymmetric(struct TreeNode *p, struct TreeNode *q){
    if (p == NULL && q == NULL) return true;
    else if (p == NULL && q != NULL) return false;
    else if (p != NULL && q == NULL) return false;
    else if (p -> val != q -> val) return false;
    else return AreSymmetric(p -> left, q -> right) && AreSymmetric(p -> right, q -> left);
}

bool isSymmetric(struct TreeNode *root){
    return AreSymmetric(root -> left, root -> right);
}