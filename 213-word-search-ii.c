#include<stdbool.h>
#include<assert.h>

struct trieItem{
    bool flag;
    struct trieItem *next[26];
};

struct trieItem* trieInitialize(){
    struct trieItem *trieTree = (struct trieItem*)malloc(sizeof(struct trieItem));
    trieTree -> flag = false;
    memset(trieTree -> next, NULL, sizeof(struct trieItem*) * 26);
    return trieTree;
}

void trieInsert(struct trieItem *trieTree, char *word){
    struct trieItem *current = trieTree;
    for (int i = 0, n = strlen(word); i < n; i += 1){
        int j = word[i] - 'a';
        if (current -> next[j] == NULL){
            current -> next[j] = (struct trieItem*)malloc(sizeof(struct trieItem));
            current -> next[j] -> flag = false;
            memset(current -> next[j] -> next, NULL, sizeof(struct trieItem*) * 26);
        }
        current = current -> next[j];
    }
    current -> flag = true;
}

char *cur;
char **ans;
int curSize;
int ansSize;

void findWord(char **board, bool *visited, int i, int j, int m, int n, struct trieItem *trieTree){
    int k = board[i][j] - 'a';
    if (trieTree -> next[k] == NULL){
        return;
    }

    visited[i * n + j] = true;
    trieTree = trieTree -> next[k];
    cur[curSize] = board[i][j];
    curSize += 1;

    if (trieTree -> flag){
        trieTree -> flag = false;
        ans[ansSize] = (char*)malloc(sizeof(char) * (curSize + 1));
        strncpy(ans[ansSize], cur, curSize);
        ans[ansSize][curSize] = '\0';
        ansSize += 1;
    }

    if (i > 0 && !visited[(i - 1) * n + j]) findWord(board, visited, i - 1, j, m, n, trieTree);
    if (j > 0 && !visited[i * n + (j - 1)]) findWord(board, visited, i, j - 1, m, n, trieTree);
    if (i < m - 1 && !visited[(i + 1) * n + j]) findWord(board, visited, i + 1, j, m, n, trieTree);
    if (j < n - 1 && !visited[i * n + (j + 1)]) findWord(board, visited, i, j + 1, m, n, trieTree);
    
    visited[i * n + j] = false;
    curSize -= 1;
}

char **findWords(char **board, int boardSize, int *boardColSize, char **words, int wordsSize, int *returnSize){
    int m = boardSize;
    int n = boardColSize[0];
    for (int i = 1; i < m; i += 1){
        assert(boardColSize[i] == n);
    }

    struct trieItem *trieTree = trieInitialize();
    for (int i = 0; i < wordsSize; i += 1){
        trieInsert(trieTree, words[i]);
    }

    bool *visited = (bool*)malloc(sizeof(bool) * m * n);
    cur = (char*)malloc(sizeof(char) * 10);
    ans = (char**)malloc(sizeof(char*) * wordsSize);
    curSize = 0;
    ansSize = 0;

    for (int i = 0; i < m; i += 1){
        for (int j = 0; j < n; j += 1){
            memset(visited, false, sizeof(bool) * m * n);
            findWord(board, visited, i, j, m, n, trieTree);
        }
    }

    *returnSize = ansSize;
    return ans;
}