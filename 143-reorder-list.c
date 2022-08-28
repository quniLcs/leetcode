#include<stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode *head){
    struct ListNode *slow = head;
    struct ListNode *fast = head -> next;
    while (fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    struct ListNode *pre = NULL;
    struct ListNode *cur = slow -> next;
    slow -> next = NULL;
    while (cur){
        struct ListNode *succ = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = succ;
    }

    struct ListNode *odd = head;
    struct ListNode *even = pre;
    while (even){
        pre = odd;
        odd = odd -> next;
        pre -> next = even;

        pre = even;
        even = even -> next;
        pre -> next = odd;
    }
}