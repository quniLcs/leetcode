#include<stdio.h>
#include<stdbool.h>
#include"uthash.h"

struct ListNode{
    int val;
    struct ListNode *next;
};

struct hashItem{
    struct ListNode *kk;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

struct hashItem *find(struct ListNode *node){
    struct hashItem *item;
    HASH_FIND_PTR(hashTable, &node, item);
    return item;
}

bool insert(struct ListNode *node){
    struct hashItem *item = find(node);
    if (item == NULL){
        item = malloc(sizeof(struct hashItem));
        item -> kk = node;
        HASH_ADD_PTR(hashTable, kk, item);
        return true;
    }
    else{
        return false;
    }    
}

bool hasCycle(struct ListNode *head){
    while (head){
        if (!insert(head)) return true;
        head = head -> next;
    }
    return false;
}