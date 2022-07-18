struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2){
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy -> val = 0;
    dummy -> next = 0;

    struct ListNode *current = dummy;
    struct ListNode *current1 = list1;
    struct ListNode *current2 = list2;

    while (current1 || current2){
        current -> next = malloc(sizeof(struct ListNode));
        current = current -> next;
        current -> next = 0;

        if (current1 && current2){
            if (current1 -> val <= current2 -> val){
                current -> val = current1 -> val;
                current1 = current1 -> next;
            }
            else{
                current -> val = current2 -> val;
                current2 = current2 -> next;
            }
        }
        else if (current1){
            current -> val = current1 -> val;
            current1 = current1 -> next;
        }
        else{
            current -> val = current2 -> val;
            current2 = current2 -> next;
        }
    }

    struct ListNode *merged = dummy -> next;
    free(dummy);
    return merged;
}