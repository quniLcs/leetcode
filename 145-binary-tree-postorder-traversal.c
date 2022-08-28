struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *ans;
int ansSize;

void postorderTraversalRecursively(struct TreeNode *root){
    if (root){
        postorderTraversalRecursively(root -> left);
        postorderTraversalRecursively(root -> right);
        ans[ansSize++] = root -> val;
    }
}

int *postorderTraversal(struct TreeNode *root, int *returnSize){
    ans = (int*)malloc(sizeof(int) * 100);
    ansSize = 0;
    postorderTraversalRecursively(root);
    *returnSize = ansSize;
    return ans;
}