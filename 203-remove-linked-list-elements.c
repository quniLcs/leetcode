struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val){
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy -> val = 0;
    dummy -> next = head;

    struct ListNode *previous = dummy;
    struct ListNode *current = head;

    while (current){
        if (current -> val == val){
            current = current -> next;
            previous -> next = current;
        }
        else{
            current = current -> next;
            previous = previous -> next;
        }
    }

    head = dummy -> next;
    free(dummy);
    return head;
}