#include<stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

// from 142-linked-list-cycle-ii.c
struct ListNode *detectCycle(struct ListNode *head){
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    do{
        if (fast == NULL || fast -> next == NULL) return NULL;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    while (slow != fast);

    struct ListNode *ans = head;
    while (ans != slow) {
        ans = ans -> next;
        slow = slow -> next;
    }
    return ans; 
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tailA = headA;
    while (tailA -> next){
        tailA = tailA -> next;
    }

    tailA -> next = headB;
    struct ListNode *ans = detectCycle(headA);
    tailA -> next = NULL;
    return ans;
}