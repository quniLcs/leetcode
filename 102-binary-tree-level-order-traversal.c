struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes){
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 2000);
    queue[0] = root;
    int head = 0;
    int tail = root ? 1 : 0;

    int **result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    *returnSize = 0;

    while (head < tail){
        int *current = (int*)malloc(sizeof(int) * 2000);
        int currentSize = 0;

        int last = tail;
        while (head < last){
            current[currentSize++] = queue[head] -> val;
            if (queue[head] -> left) queue[tail++] = queue[head] -> left;
            if (queue[head] -> right) queue[tail++] = queue[head] -> right;
            head++;
        }

        result[*returnSize] = (int*)malloc(sizeof(int) * currentSize);
        memcpy(result[*returnSize], current, sizeof(int) * currentSize);
        (*returnColumnSizes)[*returnSize] = currentSize;
        (*returnSize)++;
    }

    return result;
}