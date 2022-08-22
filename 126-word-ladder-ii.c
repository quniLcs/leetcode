#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

struct GraphNode{
    char *word;
    int index;
    int distance;
    struct GraphNode **pre;
    int preSize;
};

char ***ans;
int *ansColumnSizes;
int ansSize;

char **cur;
int curRemain;
int curSize;

void constructLadders(struct GraphNode *curNode){
    curRemain -= 1;
    cur[curRemain] = curNode->word;

    if (curRemain == 0){
        memcpy(ans[ansSize], cur, sizeof(char*) * curSize);
        ansColumnSizes[ansSize] = curSize;
        ansSize += 1;
    }
    else{
        for (int preIndex = 0; preIndex < curNode->preSize; preIndex += 1){
            constructLadders(curNode->pre[preIndex]);
        }
    }

    curRemain += 1;
}

char ***findLadders(char *beginWord, char *endWord, char **wordList, int wordListSize, int *returnSize, int **returnColumnSizes){
    // initialize
    ans = (char***)malloc(sizeof(char**) * 100);
    ansColumnSizes = (int*)malloc(sizeof(int) * 100);
    ansSize = 0;
    *returnSize = 0;
    
    // prepare the nodes
    int nodesSize = wordListSize + 1;
    struct GraphNode *node = (struct GraphNode*)malloc(sizeof(struct GraphNode) * nodesSize);

    int beginIndex = 0;
    node[0].word = beginWord;
    node[0].index = 0;
    node[0].distance = 0;
    node[0].preSize = 0;
    int wordLength = strlen(beginWord);

    int endIndex = -1;
    for (int curIndex = 1; curIndex < nodesSize; curIndex += 1){
        assert(strlen(wordList[curIndex - 1]) == wordLength);
        node[curIndex].word = wordList[curIndex - 1];
        node[curIndex].index = curIndex;
        node[curIndex].distance = -1;
        node[curIndex].preSize = 0;
        if (!strcmp(endWord, wordList[curIndex - 1])){
            endIndex = curIndex;
        }
    }
    if (endIndex == -1) return ans;

    // prepare the edges
    bool **edge = (bool**)malloc(sizeof(bool*) * nodesSize);

    for (int curIndex = 0; curIndex < nodesSize; curIndex += 1){
        edge[curIndex] = (bool*)malloc(sizeof(bool) * nodesSize);
        memset(edge[curIndex], false, sizeof(bool) * nodesSize);
    }

    for (int preIndex = 0; preIndex < nodesSize; preIndex += 1){
        for (int sucIndex = preIndex + 1; sucIndex < nodesSize; sucIndex += 1){
            int difference = 0;
            for (int charIndex = 0; charIndex < wordLength; charIndex += 1){
                if (node[preIndex].word[charIndex] != node[sucIndex].word[charIndex]){
                    difference += 1;
                }
            }
            if (difference == 1){
                edge[preIndex][sucIndex] = true;
                edge[sucIndex][preIndex] = true;
            }
        }
    }

    // search
    struct GraphNode **queue = (struct GraphNode**)malloc(sizeof(struct GraphNode*) * nodesSize);
    int head = 0;
    int tail = 0;
    queue[tail++] = &node[0];

    while (head < tail){
        for (int sucIndex = 0; sucIndex < nodesSize; sucIndex += 1){
            if (edge[queue[head]->index][sucIndex]){
                // node[sucIndex].distance == -1                        : the first time
                // node[sucIndex].distance == queue[head]->distance + 1 : not the first time
                // node[sucIndex].distance <  queue[head]->distance + 1 : not visit
                if (node[sucIndex].distance == -1){
                    node[sucIndex].distance = queue[head]->distance + 1;
                    node[sucIndex].pre = (struct GraphNode**)malloc(sizeof(struct GraphNode*) * nodesSize);
                    node[sucIndex].pre[node[sucIndex].preSize++] = queue[head];
                    queue[tail++] = &node[sucIndex];
                }
                else if (node[sucIndex].distance == queue[head]->distance + 1){
                    node[sucIndex].pre[node[sucIndex].preSize++] = queue[head];
                }
            }
        }
        head += 1;
    }
    if (node[endIndex].distance == -1) return ans;

    // construct
    curRemain = curSize = node[endIndex].distance + 1;
    cur = (char**)malloc(sizeof(char*) * curSize);
    constructLadders(&node[endIndex]);

    *returnColumnSizes = ansColumnSizes;
    *returnSize = ansSize;
    return ans;
}

void main(){
    char *beginWord = "hit";
    char *endWord = "cog";

    int wordListSize = 6;
    char **wordList = (char**)malloc(sizeof(char*) * wordListSize);
    wordList[0] = "hot";
    wordList[1] = "dot";
    wordList[2] = "dog";
    wordList[3] = "lot";
    wordList[4] = "log";
    wordList[5] = "cog";

    int returnSize;
    int *returnColumnSizes;

    char ***ans = findLadders(beginWord, endWord, wordList, wordListSize, &returnSize, &returnColumnSizes);
    for (int rowIndex = 0; rowIndex < returnSize; rowIndex += 1){
        for (int colIndex = 0; colIndex < returnColumnSizes[rowIndex]; colIndex += 1){
            printf("%s\t", ans[rowIndex][colIndex]);
        }
        printf("\n");
    }
}