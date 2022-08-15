// almost directly copied from
// https://leetcode.cn/problems/recover-binary-search-tree/solution/hui-fu-er-cha-sou-suo-shu-by-leetcode-solution/

#include<stdio.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void recoverTree(struct TreeNode *root){
    struct TreeNode **stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    int top = 0;

    struct TreeNode *previous = NULL;
    struct TreeNode *x = NULL;
    struct TreeNode *y = NULL;

    while (root || top){
        while (root){
            stack[top++] = root;
            root = root -> left;
        }
        root = stack[--top];
        if (previous && root -> val < previous -> val){
            y = root;
            if (x == NULL) x = previous;
            else break;
        }
        previous = root;
        root = root -> right;
    }

    int temp = x -> val;
    x -> val = y -> val;
    y -> val = temp;
}