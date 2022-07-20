#include<stdio.h>
#include<stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseKGroup(struct ListNode *head, int k){
    if (k == 1) return head;

    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy -> val = 0;
    dummy -> next = head;

    struct ListNode *current = dummy;
    while (1){
        struct ListNode *front = current;
        bool todo = true;
        for (int i = 0; i < k; i++){
            front = front -> next;
            if (front == NULL){
                todo = false;
                break;
            }
        }

        if (todo == false){
            break;
        }
        else{
            struct ListNode *temp = current -> next;
            current -> next = front;
            current = temp;

            temp = current -> next;
            current -> next = front -> next;

            struct ListNode *tempLast = current;
            struct ListNode *tempNext = temp -> next;
            while (1){
                temp -> next = tempLast;
                if (temp == front){
                    break;
                }
                else{
                    tempLast = temp;
                    temp = tempNext;
                    tempNext = tempNext -> next;
                }
            }
        }
    }

    struct ListNode *result = dummy -> next;
    free(dummy);
    return result;
}