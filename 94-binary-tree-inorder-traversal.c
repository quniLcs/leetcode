struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *ans;
int ansSize;

void inorderTraversalRecursively(struct TreeNode *root){
    if (root->left) inorderTraversalRecursively(root->left);
    ans[ansSize++] = root->val;
    if (root->right) inorderTraversalRecursively(root->right);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize){
    ans = (int*)malloc(sizeof(int) * 100);
    ansSize = 0;

    if (root) inorderTraversalRecursively(root);
    *returnSize = ansSize;
    return ans;
}