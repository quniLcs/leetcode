struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head){
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy -> val = 0;
    dummy -> next = head;

    struct ListNode *current = dummy;
    while (current -> next && current -> next -> next){
        struct ListNode *temp = current -> next;
        current -> next = temp -> next;
        current = current -> next;
        temp -> next = current -> next;
        current -> next = temp;
        current = temp;
    }

    struct ListNode *result = dummy -> next;
    free(dummy);
    return result;
}