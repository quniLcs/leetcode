#include<stdio.h>
#include<stdbool.h>
#include"uthash.h"

struct hashItem{
    char kk[32];
    UT_hash_handle hh;
};

struct hashItem *hashTable;

void insert(char *s){
    struct hashItem *item = malloc(sizeof(struct hashItem));
    strcpy(item->kk, s);
    HASH_ADD_STR(hashTable, kk, item);
}

bool find(char *t){
    struct hashItem *item;
    HASH_FIND_STR(hashTable, t, item);
    
    if (item) return true;
    else return false;
}

char *cur;
int curSize;
char **ans;
int ansSize;

void wordBreakRecursively(char *s, int i, int n){
    if (i == n){
        ans[ansSize] = (char*)malloc(sizeof(char) * curSize);
        strcpy(ans[ansSize], cur + 1);
        ansSize += 1;
    }
    else{
        for (int j = i + 1; j <= n ; j += 1){
            char *t = (char*)malloc(sizeof(char) * (j - i + 1));
            strncpy(t, s + i, j - i);
            t[j - i] = '\0';
            
            if (find(t)){
                cur[curSize] = ' ';
                strcpy(cur + curSize + 1, t);
                curSize += j - i + 1;
                cur[curSize] = '\0';
                wordBreakRecursively(s, j, n);
                curSize -= j - i + 1;
                cur[curSize] = '\0';
            }
        }
    }
}

char **wordBreak(char *s, char **wordDict, int wordDictSize, int *returnSize){
    hashTable = NULL;
    for (int i = 0; i < wordDictSize; i += 1){
        insert(wordDict[i]);
    }

    int n = strlen(s);
    cur = (char*)malloc(sizeof(char) * (2 * n + 1));
    ans = (char**)malloc(sizeof(char*) * (1 << (n - 1)));
    curSize = 0;
    ansSize = 0;

    wordBreakRecursively(s, 0, n);
    *returnSize = ansSize;
    return ans;    
}

void main(){
    ;
}