// with reference to:
// https://leetcode.cn/problems/unique-binary-search-trees-ii/solution/bu-tong-de-er-cha-sou-suo-shu-ii-by-leetcode-solut/

#include<stdio.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int returnSizes[9];
// n returnSize
// 0 1
// 1 1
// 2 2
// 3 5
// 4 14
// 5 42
// 6 132
// 7 429
// 8 1430

struct TreeNode **generateTreesRecursively(int start, int end){
    if (start > end){
        struct TreeNode **allTrees = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        allTrees[0] = NULL;
        return allTrees;
    }
    else{
        struct TreeNode **allTrees = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * returnSizes[end - start + 1]);
        int index = 0;
        for (int middle = start; middle <= end; middle += 1){
            int leftTreesSize = returnSizes[middle - start];
            int rightTreesSize = returnSizes[end - middle];
            struct TreeNode **leftTrees = generateTreesRecursively(start, middle - 1);
            struct TreeNode **rightTrees = generateTreesRecursively(middle + 1, end);
            for (int left = 0; left < leftTreesSize; left += 1) {
                for (int right = 0; right < rightTreesSize; right += 1) {
                    struct TreeNode *curTree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                    curTree -> val = middle;
                    curTree -> left = leftTrees[left];
                    curTree -> right = rightTrees[right];
                    allTrees[index++] = curTree;
                }
            }
            free(rightTrees);
            free(leftTrees);
        }
        return allTrees;
    }
}

struct TreeNode **generateTrees(int n, int *returnSize){
    returnSizes[0] = 1;
    for (int index = 1; index <= n; index += 1){
        returnSizes[index] = 0;
        for (int middle = 1; middle <= index; middle += 1){
            returnSizes[index] += returnSizes[middle - 1] * returnSizes[index - middle];
        }
        // printf("%d\n", returnSizes[index]);
    }
    
    *returnSize = returnSizes[n];
    return generateTreesRecursively(1, n);
}

void main(){
    int n = 3;
    int returnSize;
    generateTrees(8, &returnSize);
}