struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode *root){
    struct TreeNode *current = root;
    int maxHeight = -1;
    while (current){
        current = current -> left;
        maxHeight += 1;
    }

    if (maxHeight == -1) return 0;
    if (maxHeight == 0) return 1;
    int count = (1 << maxHeight) - 1;

    current = root;
    int curHeight = 0;
    while (curHeight <= maxHeight - 2){
        struct TreeNode *test = current -> left;
        int remain = maxHeight - curHeight - 1;
        for (int index = 0; index < remain; index += 1){
            test = test -> right;
        }
        if (test){
            count += 1 << remain;
            current = current -> right;
            curHeight += 1;
        }
        else{
            current = current -> left;
            curHeight += 1;
        }
    }
    if (current -> right) count += 2;
    else if (current -> left) count += 1;

    return count;
}