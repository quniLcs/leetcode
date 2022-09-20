#include<stdbool.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool findPath(struct TreeNode *current, struct TreeNode *p, struct TreeNode **path, int *pathSize){
    path[*pathSize] = current;
    *pathSize += 1;

    if (current == p){
        return true;
    }
    else{
        if (current -> left && findPath(current -> left, p, path, pathSize)) return true;
        if (current -> right && findPath(current -> right, p, path, pathSize)) return true;
    }

    *pathSize -= 1;
    return false;
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q){
    struct TreeNode **pPath = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100000);
    struct TreeNode **qPath = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100000);
    int pPathSize = 0;
    int qPathSize = 0;

    findPath(root, p, pPath, &pPathSize);
    findPath(root, q, qPath, &qPathSize);

    int index = 0;
    while (index < pPathSize && index < qPathSize && pPath[index] == qPath[index]){
        index += 1;
    }
    return pPath[index - 1];
}