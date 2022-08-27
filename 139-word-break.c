#include<stdio.h>
#include<stdbool.h>
#include"uthash.h"

/* original code but time limit exceeded
bool wordBreak(char *s, char **wordDict, int wordDictSize){
    if (strlen(s) == 0){
        return true;
    }
    else{
        for (int i = 0; i < wordDictSize; i += 1){
            int j = 0;
            while (wordDict[i][j]){
                if (wordDict[i][j] == s[j]) j += 1;
                else break;
            }
            if (wordDict[i][j]) continue;
            else if (wordBreak(s + j, wordDict, wordDictSize)) return true;
        }
        return false;
    }
}
*/

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

bool find(char *s, int j, int i){
    char *t = (char*)malloc(sizeof(char) * (i - j + 1));
    strncpy(t, s + j, i - j);
    t[i - j] = '\0';

    struct hashItem *item;
    HASH_FIND_STR(hashTable, t, item);
    
    if (item) return true;
    else return false;
}

bool wordBreak(char *s, char **wordDict, int wordDictSize){
    hashTable = NULL;
    for (int i = 0; i < wordDictSize; i += 1){
        insert(wordDict[i]);
    }

    int n = strlen(s);
    bool *dp = (bool*)malloc(sizeof(bool) * (n + 1));
    memset(dp, false, sizeof(bool) * (n + 1));
    dp[0] = true;
    for (int i = 1; i <= n; i += 1){
        for (int j = 0; j < i; j += 1){
            if (dp[j] && find(s, j, i)){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}