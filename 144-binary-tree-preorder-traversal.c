struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *ans;
int ansSize;

void preorderTraversalRecursively(struct TreeNode *root){
    if (root){
        ans[ansSize++] = root -> val;
        preorderTraversalRecursively(root  ->  left);
        preorderTraversalRecursively(root  ->  right);
    }
}

int *preorderTraversal(struct TreeNode *root, int *returnSize){
    ans = (int*)malloc(sizeof(int) * 100);
    ansSize = 0;
    preorderTraversalRecursively(root);
    *returnSize = ansSize;
    return ans;
}