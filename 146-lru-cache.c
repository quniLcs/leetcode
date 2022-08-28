#include<stdio.h>
#include"uthash.h"


struct listNode{
    int key;
    struct listNode *last;
    struct listNode *next;
};

struct hashItem{
    int key;
    int value;
    struct listNode *node;
    UT_hash_handle hh;
};

typedef struct{
    int current;
    int total;
    struct listNode *head;
    struct listNode *tail;
    struct hashItem *table;
}
LRUCache;


struct hashItem *hashFind(struct hashItem *table, int ikey){
    struct hashItem *item;
    HASH_FIND_INT(table, &ikey, item);
    return item;
}


LRUCache *lRUCacheCreate(int capacity){
    LRUCache *obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj -> current = 0;
    obj -> total = capacity;
    obj -> head = NULL;
    obj -> tail = NULL;
    obj -> table = NULL;
    return obj;
}

int lRUCacheGet(LRUCache *obj, int key){
    struct hashItem *item = hashFind(obj -> table, key);
}

void lRUCachePut(LRUCache *obj, int key, int value){

}

void lRUCacheFree(LRUCache *obj){

}