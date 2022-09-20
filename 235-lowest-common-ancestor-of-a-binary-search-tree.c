#include<stdbool.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q){
    struct TreeNode *ancestor = root;
    while (true){
        if (p -> val >= ancestor -> val && q -> val <= ancestor -> val) return ancestor;
        else if (p -> val <= ancestor -> val && q -> val >= ancestor -> val) return ancestor;
        else if (p -> val <= ancestor -> val && q -> val <= ancestor -> val) ancestor = ancestor -> left;
        else ancestor = ancestor -> right;
    }
}