#include<stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head){
    struct ListNode *previous = NULL;
    struct ListNode *current = head;

    while (current){
        struct ListNode *succeed = current -> next;
        current -> next = previous;
        previous = current;
        current = succeed;
    }
    return previous;
}