#include<stdio.h>
#include"uthash.h"

struct hashItem{
    char key[11];
    int val;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

struct hashItem *hashFind(char *t){
    struct hashItem *item;
    HASH_FIND_STR(hashTable, t, item);
    return item;
}

int hashEdit(char *s){
    char t[11];
    strncpy(t, s, 10);
    t[10] = '\0';

    struct hashItem *item = hashFind(t);
    if (item){
        item -> val += 1;
    }
    else{
        item = (struct hashItem*)malloc(sizeof(struct hashItem));
        strcpy(item -> key, t);
        // printf("%s\n", item -> key);
        item -> val = 1;
        HASH_ADD_STR(hashTable, key, item);
    }
    return item -> val;
}

char **findRepeatedDnaSequences(char *s, int *returnSize){
    hashTable = NULL;
    *returnSize = 0;
    for (int i = 0, n = strlen(s); i + 10 <= n; i += 1){
        if (hashEdit(s + i) == 2) *returnSize += 1;
    }

    char **ans = (char**)malloc(sizeof(char*) * (*returnSize));
    int ansSize = 0;

    struct hashItem *item, *temp;
    HASH_ITER(hh, hashTable, item, temp){
        if (item -> val > 1){
            ans[ansSize] = (char*)malloc(sizeof(char*) * 11);
            strcpy(ans[ansSize], item -> key);
            ansSize += 1;
        }
        HASH_DEL(hashTable, item);
        free(item);
    }

    return ans;
}

void main(){
    int returnSize;
    findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", &returnSize);
    printf("%d\n", returnSize);
}