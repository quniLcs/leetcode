#include<stdio.h>
#include<stdbool.h>
#include"uthash.h"

struct hashItem{
    char kk;
    int vv;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

struct hashItem *hashFind(char key){
    struct hashItem *item;
    HASH_FIND(hh, hashTable, &key, sizeof(char), item);
    return item;
}

void hashDelete(struct hashItem *item){
    HASH_DEL(hashTable, item);
    free(item);
}

void hashClear(){
    struct hashItem *item, *temp;
    HASH_ITER(hh, hashTable, item, temp){
        hashDelete(item);
    }
}

bool hashEmpty(){
    return HASH_COUNT(hashTable) == 0;
}

void hashEdit(char key, int value){
    struct hashItem *item = hashFind(key);
    if (item == NULL){
        item = malloc(sizeof(struct hashItem));
        item -> kk = key;
        item -> vv = value;
        HASH_ADD(hh, hashTable, kk, sizeof(char), item);
    }
    else{
        item -> vv += value;
        if (item -> vv == 0){
            hashDelete(item);
        }
    }
}

bool isAnagram(char *s, char *t){
    hashTable = NULL;
    for (int i = 0, n = strlen(s); i < n; i += 1) hashEdit(s[i], 1);
    for (int i = 0, n = strlen(t); i < n; i += 1) hashEdit(t[i], -1);
    bool ans = hashEmpty();
    hashClear();
    return ans;
}