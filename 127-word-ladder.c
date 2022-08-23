#include<stdbool.h>
#include<assert.h>

struct GraphNode{
    char *word;
    int index;
    int distance;
};


int ladderLength(char *beginWord, char *endWord, char **wordList, int wordListSize){
    // prepare the nodes
    int nodesSize = wordListSize + 1;
    struct GraphNode *node = (struct GraphNode*)malloc(sizeof(struct GraphNode) * nodesSize);

    int beginIndex = 0;
    node[0].word = beginWord;
    node[0].index = 0;
    node[0].distance = 0;
    int wordLength = strlen(beginWord);

    int endIndex = -1;
    for (int curIndex = 1; curIndex < nodesSize; curIndex += 1){
        assert(strlen(wordList[curIndex - 1]) == wordLength);
        node[curIndex].word = wordList[curIndex - 1];
        node[curIndex].index = curIndex;
        node[curIndex].distance = -1;
        if (!strcmp(endWord, wordList[curIndex - 1])){
            endIndex = curIndex;
        }
    }
    if (endIndex == -1) return 0;

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
                    queue[tail++] = &node[sucIndex];
                }
            }
        }
        head += 1;
    }
    return node[endIndex].distance + 1;
}