#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten(struct TreeNode *root){
    while (root && (root -> left || root -> right)){
        if (root -> left == NULL){
            root = root -> right;
        }
        else if (root -> right == NULL){
            root -> right = root -> left;
            root -> left = NULL;
            root = root -> right;
        }
        else{
            struct TreeNode *current = root -> left;
            while (current -> right) current = current -> right;
            current -> right = root -> right;
            root -> right = NULL;
        }
    }
}