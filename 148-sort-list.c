#include<stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *sortList(struct ListNode *head){
    if (head == NULL || head -> next == NULL) return head;

    // find the middle node
    struct ListNode *slow = head;
    struct ListNode *fast = head -> next;
    while (fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // partition
    struct ListNode *one = head;
    struct ListNode *two = slow -> next;
    slow -> next = NULL;

    // sort
    one = sortList(one);
    two = sortList(two);

    // merge
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *current = dummy;
    while (one && two){
        if (one -> val <= two -> val){
            current = current -> next = one;
            one = one -> next;
        }
        else{
            current = current -> next = two;
            two = two -> next;
        }
    }
    if (one) current -> next = one;
    else if (two) current -> next = two;
    return dummy -> next;
}