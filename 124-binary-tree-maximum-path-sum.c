#define INT_MIN -2147483648

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max;

int maxPathSumRecursively(struct TreeNode *root){
    int leftSum = root -> val;
    int rightSum = root -> val;
    int allSum = root -> val;
    
    if (root -> left){
        int temp = maxPathSumRecursively(root -> left);
        leftSum += temp;
        allSum += temp;
    }
    if (root -> right){
        int temp = maxPathSumRecursively(root -> right);
        rightSum += temp;
        allSum += temp;
    }
    
    if (root -> val > max) max = root -> val;
    if (leftSum > max) max = leftSum;
    if (rightSum > max) max = rightSum;
    if (allSum > max) max = allSum;

    if (root -> val > leftSum && root -> val > rightSum) return root -> val;
    else if (leftSum > rightSum) return leftSum;
    else return rightSum;
}

int maxPathSum(struct TreeNode *root){
    max = INT_MIN;
    maxPathSumRecursively(root);
    return max;
}