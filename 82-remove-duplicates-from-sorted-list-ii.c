struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head){
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy -> val = 0;
    dummy -> next = head;

    struct ListNode *current = head;
    struct ListNode *previous = dummy;
    int count = 0;

    while (previous -> next){
        if (count == 0){
            count++;
            dummy -> val = current -> val;
            current = current -> next;
        }
        else if (current && current -> val == dummy -> val){
            count++;
            current = current -> next;
        }
        else{
            if (count == 1) previous = previous -> next;
            else previous -> next = current;
            count = 0;
        }
    }

    head = dummy -> next;
    free(dummy);
    return head;
}