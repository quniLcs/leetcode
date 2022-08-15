#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool AreSymmetric(struct TreeNode *p, struct TreeNode *q){
    ;
}

bool isSymmetric(struct TreeNode *root){
    return AreSymmetric(root -> left, root -> right);
}