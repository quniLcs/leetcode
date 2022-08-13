struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int left, int right){
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy -> val = 0;
    dummy -> next = head;

    struct ListNode *current = dummy;
    for (int index = 1; index < left; index += 1){
        current = current -> next;
    }
    struct ListNode *before = current;

    struct ListNode *previous = current -> next;
    current = current -> next -> next;
    for (int index = 0; index < right - left; index += 1){
        struct ListNode *later = current -> next;
        current -> next = previous;
        previous = current;
        current = later;
    }
    before -> next -> next = current;
    before -> next = previous;

    head = dummy -> next;
    free(dummy);
    return head;
}