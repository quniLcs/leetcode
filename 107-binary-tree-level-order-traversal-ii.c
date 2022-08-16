struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int **levelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes){
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 2000);
    int *border = (int*)malloc(sizeof(int) * 2002);
    int tail;
    int level;

    tail = 0;
    border[0] = 0;
    level = 0;

    if (root){
        queue[0] = root;
        tail = 1;
        border[1] = 1;
        level = 1;
    }

    while (level && border[level] > border[level - 1]){
        for (int index = border[level - 1]; index < border[level]; index += 1){
            if (queue[index] -> left) queue[tail++] = queue[index] -> left;
            if (queue[index] -> right) queue[tail++] = queue[index] -> right;
        }
        level += 1;
        border[level] = tail;
    }
    if (level) level -= 1;

    int **result = (int**)malloc(sizeof(int*) * level);
    *returnColumnSizes = (int*)malloc(sizeof(int) * level);
    *returnSize = 0;

    while (level){
        result[*returnSize] = (int*)malloc(sizeof(int) * (border[level] - border[level - 1]));
        for (int index = border[level - 1]; index < border[level]; index += 1){
            result[*returnSize][index - border[level - 1]] = queue[index] -> val;
        }
        (*returnColumnSizes)[*returnSize] = border[level] - border[level - 1];
        (*returnSize)++;
        level--;
    }

    return result;
}