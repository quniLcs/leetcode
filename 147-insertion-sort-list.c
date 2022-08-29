#include<stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head){
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy -> val = 0;
    dummy -> next = NULL;

    struct ListNode *current = head;
    while (current){
        struct ListNode *pred = dummy;
        while (pred -> next && pred -> next -> val < current -> val){
            pred = pred -> next;
        }
        struct ListNode *succ = pred -> next;
        pred -> next = current;
        current = current -> next;
        pred -> next -> next = succ;
    }

    head = dummy -> next;
    free(dummy);
    return head;
}