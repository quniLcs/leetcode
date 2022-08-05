#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k){
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy -> val = 0;
    dummy -> next = head;

    int size = 0;
    struct ListNode *previous = dummy;
    struct ListNode *current = head;
    while (current){
        size++;
        previous = previous -> next;
        current = current -> next;
    }
    struct ListNode *last = previous;

    if (size == 0 || k % size == 0){
        return head;
    }
    else{
        // size >= 2
        // 0 < k < size
        k %= size;

        previous = dummy;
        current = head;
        for (int i = 0; i < size - k; i++){
            previous = previous -> next;
            current = current -> next;
        }

        last -> next = dummy -> next;
        previous -> next = NULL;
        return current;
    }
}