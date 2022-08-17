#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int **ans;
int *ansColumnSizes;
int ansSize;

int *cur;
int curSize;

void pathSumRecursively(struct TreeNode *root, int targetSum){
    cur[curSize] = root -> val;
    curSize++;
    
    if (root -> left == NULL && root -> right == NULL){
        if (root -> val == targetSum){
            ans[ansSize] = (int*)malloc(sizeof(int) * curSize);
            memcpy(ans[ansSize], cur, sizeof(int) * curSize);
            ansColumnSizes[ansSize] = curSize;
            ansSize++;
        }
    }
    else{
        if (root -> left != NULL) pathSumRecursively(root -> left, targetSum - root -> val);
        if (root -> right != NULL) pathSumRecursively(root -> right, targetSum - root -> val);
    }

    curSize--;
}

int **pathSum(struct TreeNode *root, int targetSum, int *returnSize, int **returnColumnSizes){
    ans = (int**)malloc(sizeof(int*) * 1000);
    ansColumnSizes = (int*)malloc(sizeof(int) * 1000);
    ansSize = 0;

    cur = (int*)malloc(sizeof(int) * 5000);
    curSize = 0;

    if (root) pathSumRecursively(root, targetSum);
    *returnColumnSizes = ansColumnSizes;
    *returnSize = ansSize;
    return ans;
}