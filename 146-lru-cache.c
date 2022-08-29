#include<stdio.h>
#include"uthash.h"


struct listNode{
    int key;
    struct listNode *last;
    struct listNode *next;
};

struct hashItem{
    int key;
    int val;
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


struct listNode *listInsert(LRUCache *obj, int ikey){
    struct listNode *node = malloc(sizeof(struct listNode));
    node -> key = ikey;
    node -> last = obj -> tail;
    node -> next = NULL;
    if (obj -> tail) obj -> tail = obj -> tail -> next = node;
    else obj -> head = obj -> tail = node;
    return node;
}

void listUpdate(LRUCache *obj, struct listNode *node){
    if (node != obj -> tail){
        if (node == obj -> head) obj -> head = obj -> head -> next;
        else node -> last -> next = node -> next;
        node -> next -> last = node -> last;
        obj -> tail -> next = node;
        node -> last = obj -> tail;
        node -> next = NULL;
        obj -> tail = node;
    }
}

int listDelete(LRUCache *obj){
    int key = obj -> head -> key;
    struct listNode *temp = obj -> head;
    if (obj -> head == obj -> tail) obj -> head = obj -> tail = NULL;
    else obj -> head = obj -> head -> next;
    free(temp);
    return key;
}


struct hashItem *hashFind(LRUCache *obj, int ikey){
    struct hashItem *item;
    HASH_FIND_INT(obj -> table, &ikey, item);
    return item;
}

void hashInsert(LRUCache *obj, int ikey, int ival, struct listNode *inode){
    struct hashItem *item = malloc(sizeof(struct hashItem));
    item -> key = ikey;
    item -> val = ival;
    item -> node = inode;
    HASH_ADD_INT(obj -> table, key, item);
}

void hashDelete(LRUCache *obj, int ikey){
    struct hashItem *item = hashFind(obj, ikey);
    HASH_DEL(obj -> table, item);
    free(item);
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
    struct hashItem *item = hashFind(obj, key);
    if (item == NULL){
        return -1;
    }
    else{
        listUpdate(obj, item -> node);
        // printf("%d\t", obj -> head -> key);
        // printf("%d\n", obj -> tail -> key);
        return item -> val;
    }
}

void lRUCachePut(LRUCache *obj, int key, int value){
    struct hashItem *item = hashFind(obj, key);
    if (item == NULL){
        if (obj -> current == obj -> total){
            hashDelete(obj, listDelete(obj));
            obj -> current -= 1;
        }
        struct listNode *node = listInsert(obj, key);
        hashInsert(obj, key, value, node);
        obj -> current += 1;
    }
    else{
        item -> val = value;
        listUpdate(obj, item -> node);
    }
    // printf("%d\t", obj -> head -> key);
    // printf("%d\n", obj -> tail -> key);
}

void lRUCacheFree(LRUCache *obj){
    struct hashItem *item, *temp;
    HASH_ITER(hh, obj -> table, item, temp){
        HASH_DEL(obj -> table, item);
        free(item -> node);
        free(item);
    }
    free(obj);
}


void main(){
    // LRUCache *obj = lRUCacheCreate(capacity);
    // int value = lRUCacheGet(obj, key);
    // lRUCachePut(obj, key, value);
    // lRUCacheFree(obj);;

    LRUCache *obj = lRUCacheCreate(2);
    lRUCachePut(obj, 1, 1);
    lRUCachePut(obj, 2, 2);
    printf("%d\n", lRUCacheGet(obj, 1));
    // printf("%d\n", lRUCacheGet(obj, 3));
    lRUCachePut(obj, 3, 3);
    printf("%d\n", lRUCacheGet(obj, 2));
}