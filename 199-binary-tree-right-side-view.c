struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *ans;
int ansSize;

void rightRecursive(struct TreeNode *root, int depth){
    ans[depth] = root -> val;
    if (depth + 1 > ansSize) ansSize = depth + 1;

    if (root -> left) rightRecursive(root -> left, depth + 1);
    if (root -> right) rightRecursive(root -> right, depth + 1);
}

int *rightSideView(struct TreeNode *root, int *returnSize){
    ans = (int*)malloc(sizeof(int) * 100);
    ansSize = 0;

    if (root) rightRecursive(root, 0);

    *returnSize = ansSize;
    return ans;
}