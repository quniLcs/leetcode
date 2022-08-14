#include<stdbool.h>
#define INT_MIN -2147483648
#define INT_MAX  2147483647

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isValidBSTRecursively(struct TreeNode *root, int min, int max){
    bool ans = root -> val >= min && root -> val <= max;
    if (root -> left) ans = ans && root -> val != INT_MIN && isValidBSTRecursively(root -> left, min, root -> val - 1);
    if (root -> right) ans = ans && root -> val != INT_MAX && isValidBSTRecursively(root -> right, root -> val + 1, max);
    return ans;
}

bool isValidBST(struct TreeNode *root){
    return isValidBSTRecursively(root, INT_MIN, INT_MAX);
}