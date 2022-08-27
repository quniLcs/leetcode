#include<stdio.h>
#include"uthash.h"

struct Node{
    int val;
    struct Node *next;
    struct Node *random;
};

struct hashItem{
    struct Node *key;
    int val;
    UT_hash_handle hh;
};

struct hashItem *hashTable;

int find(struct Node *node){
    struct hashItem *item;
    HASH_FIND(hh, hashTable, &node, sizeof(struct Node*), item);
    return item->val;
}

void insert(struct Node *node, int index){
    struct hashItem *item = malloc(sizeof(struct hashItem));
    item->key = node;
    item->val = index;
    HASH_ADD(hh, hashTable, key, sizeof(struct Node*), item);
}

struct Node *copyRandomList(struct Node *head){
    hashTable = NULL;

	struct Node *current = head;
    int length = 0;
    while (current){
        insert(current, length);
        current = current->next;
        length += 1;
    }

    if (length == 0) return NULL;
    struct Node *new = (struct Node *)malloc(sizeof(struct Node) * length);
    for (int index = 0; index < length; index += 1){
        new[index].val = head->val;
        new[index].next = index == length - 1 ? NULL : &new[index + 1];
        new[index].random = head->random ? &new[find(head->random)] : NULL;
        head = head->next;
    }
    return new;
}