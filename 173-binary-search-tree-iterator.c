#include<stdio.h>
#include<stdbool.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct LinkedNode{
    struct TreeNode *val;
    struct LinkedNode *next;
};

typedef struct{
    struct LinkedNode *head;
}
BSTIterator;


BSTIterator *bSTIteratorCreate(struct TreeNode *root){
    BSTIterator *obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj -> head = NULL;

    while (root){
        struct LinkedNode *current = (struct LinkedNode*)malloc(sizeof(struct LinkedNode));
        current -> val = root;
        current -> next = obj -> head;
        obj -> head = current;
        root = root -> left;
    }

    /*
    struct LinkedNode *current = (struct LinkedNode*)malloc(sizeof(struct LinkedNode));
    current -> val = NULL;
    current -> next = obj -> head;
    obj -> head = current;
    */

    return obj;
}

int bSTIteratorNext(BSTIterator *obj){
    int ans = obj -> head -> val -> val;

    struct LinkedNode *old = obj -> head;
    struct TreeNode *root = obj -> head -> val -> right;
    obj -> head = obj -> head -> next;
    while (root){
        struct LinkedNode *current = (struct LinkedNode*)malloc(sizeof(struct LinkedNode));
        current -> val = root;
        current -> next = obj -> head;
        obj -> head = current;
        root = root -> left;
    }
    free(old);

    return ans;
}

bool bSTIteratorHasNext(BSTIterator *obj){
    if (obj -> head) return true;
    else return false;
}

void bSTIteratorFree(BSTIterator *obj){
    while (obj -> head){
        struct LinkedNode *old = obj -> head;
        obj -> head = obj -> head -> next;
        free(old);
    }
    free(obj);
}

/**
BSTIterator* obj = bSTIteratorCreate(root);
int val = bSTIteratorNext(obj);
bool ans = bSTIteratorHasNext(obj);
bSTIteratorFree(obj);
*/