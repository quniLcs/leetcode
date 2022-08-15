#include<stdbool.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes){
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 2000);
    queue[0] = root;
    int head = 0;
    int tail = root ? 1 : 0;
    bool reverse = false;

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
        for (int index = 0; index < currentSize; index++){
            result[*returnSize][index] = current[reverse ? currentSize - index - 1 : index];
        }
        (*returnColumnSizes)[*returnSize] = currentSize;
        (*returnSize)++;
        reverse = !reverse;
    }

    return result;
}