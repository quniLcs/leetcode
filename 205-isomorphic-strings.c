#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include"uthash.h"

struct SetItem{
    char kk;
    UT_hash_handle hh;
};

struct DictItem{
    char kk;
    char vv;
    UT_hash_handle hh;
};

struct SetItem *set;
struct DictItem *dict;

bool SetFind(char key){
    struct SetItem *item;
    HASH_FIND(hh, set, &key, sizeof(char), item);
    if (item) return true;
    else return false;
}

void SetInsert(char key){
    struct SetItem *item = malloc(sizeof(struct SetItem));
    item -> kk = key;
    HASH_ADD(hh, set, kk, sizeof(char), item);
}

struct DictItem *DictFind(char key){
    struct DictItem *item;
    HASH_FIND(hh, dict, &key, sizeof(char), item);
    return item;
}

void DictInsert(char key, char val){
    struct DictItem *item = malloc(sizeof(struct DictItem));
    item -> kk = key;
    item -> vv = val;
    HASH_ADD(hh, dict, kk, sizeof(char), item);
}

bool isIsomorphic(char *s, char *t){
    int n = strlen(s);
    assert(strlen(t) == n);

    set = NULL;
    dict = NULL;

    for (int i = 0; i < n ; i += 1){
        struct DictItem *item = DictFind(s[i]);
        if (item){
            if (t[i] != item -> vv){
                return false;
            }
        }
        else{
            if (SetFind(t[i])){
                return false;
            }
            else{
                SetInsert(t[i]);
                DictInsert(s[i], t[i]);
            }
        }
    }
    return true;
}

void main(){
    isIsomorphic("paper", "title");
}