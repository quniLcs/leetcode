struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *current = head;

    while (current && current -> next){
        if (current -> next -> val == current -> val){
            current -> next = current -> next -> next;
        }
        else{
            current = current -> next;
        }
    }

    return head;
}