#include<stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode *node){
    while (node -> next -> next){
        node -> val = node -> next -> val;
        node = node -> next;
    }
    node -> val = node -> next -> val;
    free(node -> next);
    node -> next = NULL;
}